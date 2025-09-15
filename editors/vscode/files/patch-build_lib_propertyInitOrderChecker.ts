--- build/lib/propertyInitOrderChecker.ts.orig	2025-09-09 22:02:15 UTC
+++ build/lib/propertyInitOrderChecker.ts
@@ -43,7 +43,7 @@ function createProgram(tsconfigPath: string): ts.Progr
 function createProgram(tsconfigPath: string): ts.Program {
 	const tsConfig = ts.readConfigFile(tsconfigPath, ts.sys.readFile);
 
-	const configHostParser: ts.ParseConfigHost = { fileExists: fs.existsSync, readDirectory: ts.sys.readDirectory, readFile: file => fs.readFileSync(file, 'utf8'), useCaseSensitiveFileNames: process.platform === 'linux' };
+	const configHostParser: ts.ParseConfigHost = { fileExists: fs.existsSync, readDirectory: ts.sys.readDirectory, readFile: file => fs.readFileSync(file, 'utf8'), useCaseSensitiveFileNames: (process.platform === 'linux' || process.platform === 'freebsd') };
 	const tsConfigParsed = ts.parseJsonConfigFileContent(tsConfig.config, configHostParser, path.resolve(path.dirname(tsconfigPath)), { noEmit: true });
 
 	const compilerHost = ts.createCompilerHost(tsConfigParsed.options, true);
