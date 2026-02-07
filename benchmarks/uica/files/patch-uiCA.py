--- uiCA.py.orig	2022-07-21 20:16:37 UTC
+++ uiCA.py
@@ -2077,7 +2077,7 @@ def generateHTMLTraceTable(filename, instructions, ins
                      uopData['events'][evCycle] = ev
       prevInstrI = instrI
 
-   with open(os.path.join(os.path.dirname(os.path.realpath(__file__)), 'traceTemplate.html'), 'r') as t:
+   with open('%%DATADIR%%/traceTemplate.html', 'r') as t:
       html = t.read()
       html = html.replace('var tableData = {}', 'var tableData = ' + json.dumps(tableDataForRnd))
 
