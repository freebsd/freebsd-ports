<?php
/**
 * List of all included plugins can be found at the
 * beginning of index.php
 */
return [
        new AdminerDarkSwitcher,

        new AdminerPrettyJsonColumn,

        new AdminerDumpJson,

        new AdminerDumpXml,

        // install zip extension to use this
        new AdminerDumpZip,

        // install bz2 extension to use this
        new AdminerDumpBz2,
];
