
$FreeBSD$

--- lib/sasl/src/rb.erl.orig
+++ lib/sasl/src/rb.erl
@@ -177,7 +177,7 @@
     {reply, ok, State#state{device = standard_io}};
 handle_call({show_number, Number}, _From, State) ->
     #state{dir = Dir, data = Data, device = Device, abort = Abort, log = Log} = State,
-    NewDevice = print_report(Dir, Data, Number, Device, Abort, Log),
+    NewDevice = print_report_by_num(Dir, Data, Number, Device, Abort, Log),
     {reply, ok, State#state{device = NewDevice}};
 handle_call({show_type, Type}, _From, State) ->
     #state{dir = Dir, data = Data, device = Device, abort = Abort, log = Log} = State,
@@ -541,6 +541,10 @@
 		       io_lib:format("~s", [ShortDescr]),
 		       Date]).
 
+print_report_by_num(Dir, Data, Number, Device, Abort, Log) ->
+    {_,Device1} = print_report(Dir, Data, Number, Device, Abort, Log),
+    Device1.
+    
 print_typed_reports(_Dir, [], _Type, Device, _Abort, _Log) ->
     Device;
 print_typed_reports(Dir, Data, Type, Device, Abort, Log) ->
@@ -569,23 +573,29 @@
     end.
 
 print_report(Dir, Data, Number, Device, Abort, Log) ->
-    {Fname, FilePosition} = find_report(Data, Number),
-    FileName = lists:concat([Dir, Fname]),
-    case file:open(FileName, read) of
-	{ok, Fd} -> 
-	    read_rep(Fd, FilePosition, Device, Abort, Log);
-	_ -> 
-	    io:format("rb: can't open file ~p~n", [Fname]),
+    case find_report(Data, Number) of
+	{Fname, FilePosition} ->
+	    FileName = lists:concat([Dir, Fname]),
+	    case file:open(FileName, read) of
+		{ok, Fd} -> 
+		    read_rep(Fd, FilePosition, Device, Abort, Log);
+		_ -> 
+		    io:format("rb: can't open file ~p~n", [Fname]),
+		    {proceed,Device}
+	    end;
+	no_report ->
 	    {proceed,Device}
     end.
 
 find_report([{No, _Type, _Descr, _Date, Fname, FilePosition}|_T], No) ->
     {Fname, FilePosition};
-find_report([_H|T], No) -> find_report(T, No);
+find_report([_H|T], No) -> 
+    find_report(T, No);
 find_report([], No) ->
-    io:format("There is no report with number ~p.~n", [No]).
+    io:format("There is no report with number ~p.~n", [No]),
+    no_report.
     
-print_grep_reports(_Dir, [], _RegExp, Device, Abort, Log) ->
+print_grep_reports(_Dir, [], _RegExp, Device, _Abort, _Log) ->
     Device;
 print_grep_reports(Dir, Data, RegExp, Device, Abort, Log) ->
     {Next,Device1} = print_grep_report(Dir, Data, element(1, hd(Data)), 
