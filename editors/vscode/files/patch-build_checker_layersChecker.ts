--- build/checker/layersChecker.ts.orig	2025-07-12 04:56:20 UTC
+++ build/checker/layersChecker.ts
@@ -136,7 +136,7 @@ function createProgram(tsconfigPath: string): ts.Progr
 function createProgram(tsconfigPath: string): ts.Program {
 	const tsConfig = ts.readConfigFile(tsconfigPath, ts.sys.readFile);
 
-	const configHostParser: ts.ParseConfigHost = { fileExists: existsSync, readDirectory: ts.sys.readDirectory, readFile: file => readFileSync(file, 'utf8'), useCaseSensitiveFileNames: process.platform === 'linux' };
+	const configHostParser: ts.ParseConfigHost = { fileExists: existsSync, readDirectory: ts.sys.readDirectory, readFile: file => readFileSync(file, 'utf8'), useCaseSensitiveFileNames: (process.platform === 'linux' || process.platform === 'freebsd') };
 	const tsConfigParsed = ts.parseJsonConfigFileContent(tsConfig.config, configHostParser, resolve(dirname(tsconfigPath)), { noEmit: true });
 
 	const compilerHost = ts.createCompilerHost(tsConfigParsed.options, true);
