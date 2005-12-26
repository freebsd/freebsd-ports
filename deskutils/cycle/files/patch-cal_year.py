--- cal_year.py.orig
+++ cal_year.py
@@ -45,15 +45,20 @@
 	wx.calendar.CalendarCtrl.__init__(self, parent, id, dt, pos, size, style)
 	self.SetBackgroundColour(wx.WHITE)
 	self.SetHeaderColours(wx.BLACK,wx.WHITE)
-	if '__WXMSW__' in wx.PlatformInfo:
+	#if '__WXMSW__' in wx.PlatformInfo:
+	if False:
 	    font = self.GetFont()
 	    font.SetFaceName("MS Sans Serif")
 	    self.SetFont(font)
 	
-	self.Bind(wx.EVT_RIGHT_DOWN, self.OnRightDown)
-	self.Bind(wx.EVT_LEFT_DOWN, self.OnLeftDown)
-	self.Bind(wx.EVT_KEY_UP, self.OnKey)
-	self.Bind(wx.EVT_KEY_DOWN, self.OnKey)
+	#self.Bind(wx.EVT_RIGHT_DOWN, self.OnRightDown)
+	wx.EVT_RIGHT_DOWN(self, self.OnRightDown)
+	#self.Bind(wx.EVT_LEFT_DOWN, self.OnLeftDown)
+	wx.EVT_LEFT_DOWN(self, self.OnLeftDown)
+	#self.Bind(wx.EVT_KEY_UP, self.OnKey)
+	wx.EVT_KEY_UP(self, self.OnKey)
+	#self.Bind(wx.EVT_KEY_DOWN, self.OnKey)
+	wx.EVT_KEY_DOWN(self, self.OnKey)
 	self.d_click=wx.DateTime()#FromDMY(1, 0,2002)
 	
     def OnLeftDown(self, event):
@@ -80,10 +85,14 @@
 	    menu.AppendCheckItem(4, _('Note'))
 	    menu.Check(4,is_set_mark(d, MARK_NOTE, d.GetYear()))
 	    
-	    self.Bind(wx.EVT_MENU, self.OnBegin, id=2)
-	    self.Bind(wx.EVT_MENU, self.OnLast, id=3)
-	    self.Bind(wx.EVT_MENU, self.OnNote, id=4)
-	    self.Bind(wx.EVT_MENU, self.OnTablet, id=5)
+	    #self.Bind(wx.EVT_MENU, self.OnBegin, id=2)
+	    wx.EVT_MENU(self, 2, self.OnBegin)
+	    #self.Bind(wx.EVT_MENU, self.OnLast, id=3)
+	    wx.EVT_MENU(self, 3, self.OnLast)
+	    #self.Bind(wx.EVT_MENU, self.OnNote, id=4)
+	    wx.EVT_MENU(self, 4, self.OnNote)
+	    #self.Bind(wx.EVT_MENU, self.OnTablet, id=5)
+	    wx.EVT_MENU(self, 5, self.OnTablet)
 	    self.PopupMenu(menu, event.GetPosition())
 	    menu.Destroy()
 
@@ -139,8 +148,8 @@
 
     def OnKey(self, event):
 	k=event.GetKeyCode()
-	if k==WXK_LEFT or k==WXK_RIGHT or \
-	   k==WXK_UP or k==WXK_DOWN:
+	if k==wx.WXK_LEFT or k==wx.WXK_RIGHT or \
+	   k==wx.WXK_UP or k==wx.WXK_DOWN:
 	    pass
 	else:
 	    event.Skip()
@@ -337,7 +346,8 @@
 
     last_6=[]
     for k in range(i,0,-1):
-	span=(cycle.begin[k]-cycle.begin[k-1]+wx.TimeSpan.Hours(1)).GetDays()
+	#span=(cycle.begin[k]-cycle.begin[k-1]+wx.TimeSpan.Hours(1)).GetDays()
+	span=(cycle.begin[k]-cycle.begin[k-1]+wx.TimeSpan_Hours(1)).GetDays()
 	# wx.TimeSpan.Hours(1) - компенсация потери часа на летнем времени
 	if 20 < span <36: # остальное в расчет не берем
 	    last_6.append(span)
@@ -367,27 +377,34 @@
     for d in cycle.begin:
 	i=cycle.begin.index(d)
 	if i<len(cycle.begin)-1:
-	    if (cycle.begin[i+1]-cycle.begin[i]+wx.TimeSpan.Hours(1)).GetDays()<21:
+	    #if (cycle.begin[i+1]-cycle.begin[i]+wx.TimeSpan.Hours(1)).GetDays()<21:
+	    if (cycle.begin[i+1]-cycle.begin[i]+wx.TimeSpan_Hours(1)).GetDays()<21:
 		# wx.TimeSpan.Hours(1) - потеря одного часа при переходе на
 		# летнее время
 		continue
 
 	min, max = min_max(i)
-	begin = d+wx.DateSpan.Days( min-18 ) # begin fertile
-	end = d+wx.DateSpan.Days( max-11 ) # end fertile
-        ovul=end-wx.DateSpan.Days(((max-11)-(min-18))/2) #day of ovul
+	#begin = d+wx.DateSpan.Days( min-18 ) # begin fertile
+	begin = d+wx.DateSpan_Days( min-18 ) # begin fertile
+	#end = d+wx.DateSpan.Days( max-11 ) # end fertile
+	end = d+wx.DateSpan_Days( max-11 ) # end fertile
+	#ovul=end-wx.DateSpan.Days(((max-11)-(min-18))/2) #day of ovul
+	ovul=end-wx.DateSpan_Days(((max-11)-(min-18))/2) #day of ovul
 	if year_b<=ovul<=year_e:
 	    add_mark(ovul, MARK_OVUL, year)
 
 	start=d+wx.DateSpan_Day()
 	if i<len(cycle.begin)-1:
-	    last_cycle=(cycle.begin[i+1]-cycle.begin[i]+wx.TimeSpan.Hours(1)).GetDays()
+	    #last_cycle=(cycle.begin[i+1]-cycle.begin[i]+wx.TimeSpan.Hours(1)).GetDays()
+	    last_cycle=(cycle.begin[i+1]-cycle.begin[i]+wx.TimeSpan_Hours(1)).GetDays()
 	    if last_cycle>35:
-		stop=d+wx.DateSpan.Days( 35 )
+		#stop=d+wx.DateSpan.Days( 35 )
+		stop=d+wx.DateSpan_Days( 35 )
 	    else:
 		stop=cycle.begin[i+1]-wx.DateSpan_Day()
 	else:
-	    stop=d+wx.DateSpan.Days( cycle.period-1 )
+	    #stop=d+wx.DateSpan.Days( cycle.period-1 )
+	    stop=d+wx.DateSpan_Days( cycle.period-1 )
 
 	if (stop<year_b or start>year_e) and (d not in cycle.last):
 	    continue
@@ -400,7 +417,8 @@
 	    f=f+wx.DateSpan_Day()
 	
 	if d in cycle.last: # calc birthday
-	    birth = d+wx.DateSpan.Days(280+cycle.period-28)
+	    #birth = d+wx.DateSpan.Days(280+cycle.period-28)
+	    birth = d+wx.DateSpan_Days(280+cycle.period-28)
 	    if i<len(cycle.begin)-1: # not last item
 		if birth < cycle.begin[i+1]:
 		    add_mark(birth, MARK_BIRTH, year)
@@ -410,7 +428,8 @@
 		
     # prognosis to future cycles
     cycle.prog_begin=[]
-    d=d+wx.DateSpan.Days( cycle.period )
+    #d=d+wx.DateSpan.Days( cycle.period )
+    d=d+wx.DateSpan_Days( cycle.period )
     while d.GetYear()<=year:
 	if cycle.tablet<>[] and cycle.tablet[-1]<=d and \
 	    cycle.begin[-1]<=cycle.tablet[-1]: return
@@ -418,15 +437,21 @@
 	    #	    cycle.prog_begin.append(d)
 	    add_mark(d, MARK_PROG, year)
 
-	begin = d+wx.DateSpan.Days( min-18 ) #начало периода
-	end = d+wx.DateSpan.Days( max-11 ) #конец периода
-	ovul=end-wx.DateSpan.Days(((max-11)-(min-18))/2) #day of ovul
+	#begin = d+wx.DateSpan.Days( min-18 ) #начало периода
+	begin = d+wx.DateSpan_Days( min-18 ) #начало периода
+	#end = d+wx.DateSpan.Days( max-11 ) #конец периода
+	end = d+wx.DateSpan_Days( max-11 ) #конец периода
+	#ovul=end-wx.DateSpan.Days(((max-11)-(min-18))/2) #day of ovul
+	ovul=end-wx.DateSpan_Days(((max-11)-(min-18))/2) #day of ovul
 	if year_b<=ovul<=year_e:
 	    add_mark(ovul, MARK_OVUL, year)
 
-	start=d+wx.DateSpan.Day()
-	stop=d+wx.DateSpan.Days( cycle.period-1 )
-	d=d+wx.DateSpan.Days( cycle.period )
+	#start=d+wx.DateSpan.Day()
+	start=d+wx.DateSpan_Day()
+	#stop=d+wx.DateSpan.Days( cycle.period-1 )
+	stop=d+wx.DateSpan_Days( cycle.period-1 )
+	#d=d+wx.DateSpan.Days( cycle.period )
+	d=d+wx.DateSpan_Days( cycle.period )
 	
         if stop<year_b or start>year_e : continue
 	
@@ -448,15 +473,19 @@
     for d in cycle.tablet:
 	i=cycle.tablet.index(d)
 	if i<len(cycle.tablet)-1:
-	    if (cycle.tablet[i+1]-cycle.tablet[i]+wx.TimeSpan.Hours(1)).GetDays()<28:
+	    #if (cycle.tablet[i+1]-cycle.tablet[i]+wx.TimeSpan.Hours(1)).GetDays()<28:
+	    if (cycle.tablet[i+1]-cycle.tablet[i]+wx.TimeSpan_Hours(1)).GetDays()<28:
 		#incorrect using - must more 28 days
 		continue
 	for k in range(28):
-	    remove_mark(d+wx.DateSpan.Days(k), MARK_PROG | MARK_FERT |
+	    #remove_mark(d+wx.DateSpan.Days(k), MARK_PROG | MARK_FERT |
+	    remove_mark(d+wx.DateSpan_Days(k), MARK_PROG | MARK_FERT |
 	    MARK_NEXT_TABLET | MARK_OVUL | MARK_SAFESEX | MARK_BIRTH, year)
         for k in range(21,28):
-	    add_mark(d+wx.DateSpan.Days(k), MARK_T22_28, year)
-	add_mark(d+wx.DateSpan.Days(28), MARK_NEXT_TABLET, year)
+	    #add_mark(d+wx.DateSpan.Days(k), MARK_T22_28, year)
+	    add_mark(d+wx.DateSpan_Days(k), MARK_T22_28, year)
+	#add_mark(d+wx.DateSpan.Days(28), MARK_NEXT_TABLET, year)
+	add_mark(d+wx.DateSpan_Days(28), MARK_NEXT_TABLET, year)
 		
 
 	    
@@ -502,8 +531,10 @@
     s=day.Format('%d %B')
     if cycle.tablet<>[]:
 	for d in cycle.tablet:
-	    if day.IsBetween(d, d+wx.DateSpan.Days(28)):
-		t=(day-d+wx.TimeSpan.Hours(1)).GetDays()+1
+	    #if day.IsBetween(d, d+wx.DateSpan.Days(28)):
+	    if day.IsBetween(d, d+wx.DateSpan_Days(28)):
+		#t=(day-d+wx.TimeSpan.Hours(1)).GetDays()+1
+		t=(day-d+wx.TimeSpan_Hours(1)).GetDays()+1
 		s+=" - "
 		if t<=28:
 		    s+=_('tablet N ')+str(t)
@@ -532,7 +563,8 @@
 	    while d<=day:
 		if cycle.tablet<>[] and cycle.tablet[-1]<=d and \
 		    cycle.begin[-1]<=cycle.tablet[-1]: return s
-		d=d+wx.DateSpan.Days(cycle.period)
+		#d=d+wx.DateSpan.Days(cycle.period)
+		d=d+wx.DateSpan_Days(cycle.period)
 	    find=2
 
 
@@ -543,10 +575,12 @@
 	if d2 in cycle.last:
 	    gestation=1
     elif find==2:
-        d2=d-wx.DateSpan.Days(cycle.period)
+        #d2=d-wx.DateSpan.Days(cycle.period)
+        d2=d-wx.DateSpan_Days(cycle.period)
     
     if gestation:
-	k=(day-d2+wx.TimeSpan.Hours(1)).GetDays()+1
+	#k=(day-d2+wx.TimeSpan.Hours(1)).GetDays()+1
+	k=(day-d2+wx.TimeSpan_Hours(1)).GetDays()+1
 	w=(k-1)/7
 	s+=" - "+str(k)+_(' day of gestation, ')+str(w)
 	if w == 1: s+=_(' week')
@@ -555,10 +589,13 @@
 	if (k-w*7) == 1: s+=_(' day')
 	else: s+=_(' days')
     else:
-	p=(d-d2+wx.TimeSpan.Hours(1)).GetDays()
-	k=(day-d2+wx.TimeSpan.Hours(1)).GetDays()+1
+	#p=(d-d2+wx.TimeSpan.Hours(1)).GetDays()
+	p=(d-d2+wx.TimeSpan_Hours(1)).GetDays()
+	#k=(day-d2+wx.TimeSpan.Hours(1)).GetDays()+1
+	k=(day-d2+wx.TimeSpan_Hours(1)).GetDays()+1
 
-	d=d-wx.DateSpan.Day()
+	#d=d-wx.DateSpan.Day()
+	d=d-wx.DateSpan_Day()
 	s+=" - "+str(k)+_(' day of period from ')+d2.Format('%d %b')+_(' to ')+\
 	    d.Format('%d %b')+_(' length ')+str(p)+_(' days')
     return s
