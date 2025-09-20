<?php
/***********************************************************
 * 
 *   Merges adminer.php and it's plugins to a phar archive
 * 
 ***********************************************************/

$phar = new Phar(
    $tmpFile = __DIR__ . '/adminer_' . bin2hex(random_bytes(8)) . '.phar',
    0,
    'adminer.phar'
);

$stub = <<<STUB
<?php
/******************************************************************************
 *  
 *  All Adminer plugins are now included in this
 *  FreeBSD ports edition, no need to download
 *  them separately.
 *  https://www.adminer.org/en/plugins/
 *  
 *  copyright Paavo-Einari Kaipila (FreeBSD ports edition)
 *  copyright Jakub Vrana          (original Adminer)
 * 
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *  
 *  http://www.apache.org/licenses/LICENSE-2.0
 *  
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 * 
 ******************************************************************************/
if (file_exists(\$adminerObjectFile = __DIR__ . '/adminer-object.php'))
{
    require \$adminerObjectFile;
}
Phar::mapPhar('adminer.phar');
define('ADMINER_PLUGIN_CLASSMAP', json_decode('%s', true));
require 'phar://adminer.phar/autoload.php';
__HALT_COMPILER();
STUB;

$classMap = [];
$plugins = [];

foreach(new DirectoryIterator(__DIR__ . '/plugins') as $file)
{
    if ($file->isFile())
    {
        $contents = php_strip_whitespace($file->getRealPath());
        $fileName = $file->getFileName();
        $pharFile = 'adminer-plugins/' . $fileName;

        if (
            /**
             * Skip affected plugin
             * https://nvd.nist.gov/vuln/detail/CVE-2023-45197
             */
            $fileName !== 'file-upload.php'
            /**
             * Adminer editor's plugins are only relevant
             * in Adminer editor.
             */
            && !str_starts_with($fileName, 'editor')
            && preg_match('/class\s(A[a-zA-Z0-9]+)\sextends\sAdminer/', $contents, $m)
        ) {
            $plugins[$pharFile] = $contents;
            $classMap[$m[1]] = $file->getFileName();
        }
    }
}

ksort($classMap);

$phar->setStub(
    sprintf(
        $stub,
        json_encode($classMap, JSON_UNESCAPED_SLASHES | JSON_PRETTY_PRINT)
    )
);

$autoLoader = <<<LOADER
<?php
spl_autoload_register(function(\$class)
{
    if (isset(ADMINER_PLUGIN_CLASSMAP[\$class]))
    {
        require __DIR__ . '/adminer-plugins/' . ADMINER_PLUGIN_CLASSMAP[\$class];
        return true;
    }
});
require __DIR__ . '/adminer.php';
LOADER;

$phar->addFromString(
    'autoload.php',
    $autoLoader
);

foreach($plugins as $file => $contents)
{
    $phar->addFromString(
        $file,
        $contents
    );
}

$phar->addFromString(
    'adminer.php',
    php_strip_whitespace(__DIR__ . '/adminer.php'),
);

rename($tmpFile, __DIR__ . '/index.php');
