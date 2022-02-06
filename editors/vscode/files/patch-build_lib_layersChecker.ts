--- build/lib/layersChecker.ts.orig	2022-02-02 16:57:24 UTC
+++ build/lib/layersChecker.ts
@@ -294,7 +294,7 @@ function checkFile(program: ts.Program, sourceFile: ts
 function createProgram(tsconfigPath: string): ts.Program {
 	const tsConfig = ts.readConfigFile(tsconfigPath, ts.sys.readFile);
 
-	const configHostParser: ts.ParseConfigHost = { fileExists: existsSync, readDirectory: ts.sys.readDirectory, readFile: file => readFileSync(file, 'utf8'), useCaseSensitiveFileNames: process.platform === 'linux' };
+	const configHostParser: ts.ParseConfigHost = { fileExists: existsSync, readDirectory: ts.sys.readDirectory, readFile: file => readFileSync(file, 'utf8'), useCaseSensitiveFileNames: (process.platform === 'linux' || process.platform === 'freebsd') };
 	const tsConfigParsed = ts.parseJsonConfigFileContent(tsConfig.config, configHostParser, resolve(dirname(tsconfigPath)), { noEmit: true });
 
 	const compilerHost = ts.createCompilerHost(tsConfigParsed.options, true);
