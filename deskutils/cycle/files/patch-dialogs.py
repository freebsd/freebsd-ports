--- dialogs.py.orig
+++ dialogs.py
@@ -9,8 +9,8 @@
 import wx
 import wx.html
 from cal_year import cycle , Val
-from save_load import Load_Cycle, get_f_name
-
+from save_load import Load_Cycle, get_f_name, set_color_default
+from set_dir import *
 #---------------------------------------------------------------------------
 class Settings_Dlg(wx.Dialog):
     def __init__(self, parent):
@@ -23,7 +23,8 @@
 	i=wx.NewId()
 	self.cb1 = wx.CheckBox(self, i, _(' by average'), style=wx.NO_BORDER)
 	b1.Add(self.cb1, 0, wx.ALL, 5)
-	self.Bind(wx.EVT_CHECKBOX, self.By_Average, id=i)
+	#self.Bind(wx.EVT_CHECKBOX, self.By_Average, id=i)
+	wx.EVT_CHECKBOX(self, i, self.By_Average)
 	self.cb1.SetValue(cycle.by_average)
 
 	b2 = wx.BoxSizer(wx.HORIZONTAL)
@@ -58,21 +59,25 @@
 	w2,h=self.GetTextExtent(txt2)
 	w = max(w1, w2)
 	box.Add(wx.Button(self, i, txt1, size=wx.Size(w+10, -1)), 0, wx.ALIGN_CENTER)
-	self.Bind(wx.EVT_BUTTON, self.OnColours, id=i)
+	#self.Bind(wx.EVT_BUTTON, self.OnColours, id=i)
+	wx.EVT_BUTTON(self, i, self.OnColours)
 	#======================
 	i=wx.NewId()
 	box.Add(wx.Button(self, i, txt2, size=wx.Size(w+10, -1)), 0, wx.TOP|wx.ALIGN_CENTER,10)
-	self.Bind(wx.EVT_BUTTON, self.OnChangePasswd, id=i)
+	#self.Bind(wx.EVT_BUTTON, self.OnChangePasswd, id=i)
+	wx.EVT_BUTTON(self, i, self.OnChangePasswd)
 
 	#======================
 	but_box=wx.BoxSizer(wx.HORIZONTAL)
 	i=wx.NewId()
 	but_box.Add(wx.Button(self, i, _('Ok')), 0, wx.ALL, 10)
-	self.Bind(wx.EVT_BUTTON, self.OnOk, id=i)
+	#self.Bind(wx.EVT_BUTTON, self.OnOk, id=i)
+	wx.EVT_BUTTON(self, i, self.OnOk)
 	
 	i=wx.NewId()
 	but_box.Add(wx.Button(self, i, _('Cancel')), 0, wx.ALL, 10)
-	self.Bind(wx.EVT_BUTTON, self.OnCancel, id=i)
+	#self.Bind(wx.EVT_BUTTON, self.OnCancel, id=i)
+	wx.EVT_BUTTON(self, i, self.OnCancel)
 
 	box.Add(but_box, 0, wx.ALIGN_CENTER)
 
@@ -135,11 +140,13 @@
 	b1=wx.BoxSizer(wx.HORIZONTAL)
 	i=wx.NewId()
 	b1.Add(wx.Button(self, i, _('Ok')), 0, wx.ALL, 10)
-	self.Bind(wx.EVT_BUTTON, self.OnOk, id=i)
+	#self.Bind(wx.EVT_BUTTON, self.OnOk, id=i)
+	wx.EVT_BUTTON(self, i, self.OnOk)
 	
 	i=wx.NewId()
 	b1.Add(wx.Button(self, i, _('Cancel')), 0, wx.ALL, 10)
-	self.Bind(wx.EVT_BUTTON, self.OnCancel, id=i)
+	#self.Bind(wx.EVT_BUTTON, self.OnCancel, id=i)
+	wx.EVT_BUTTON(self, i, self.OnCancel)
 	self.pass1.SetFocus()
 	box.Add(b1, 0, wx.ALIGN_CENTER)
 
@@ -185,7 +192,7 @@
 	#======== List users ==============
 	i = wx.NewId()
         self.il = wx.ImageList(16, 16,True)
-	bmp=wx.Bitmap('bitmaps/smiles.bmp', wx.BITMAP_TYPE_BMP)
+	bmp=wx.Bitmap(os.path.join(bitmaps_dir, 'smiles.bmp'), wx.BITMAP_TYPE_BMP)
 	mask = wx.Mask(bmp, wx.WHITE)
 	bmp.SetMask(mask)
 	
@@ -201,25 +208,30 @@
 	self.list.SetItemState(0, wx.LIST_STATE_SELECTED, wx.LIST_STATE_SELECTED)
 	self.name=users[0]
 	
-	self.list.Bind(wx.EVT_LIST_ITEM_SELECTED, self.OnItemSelected, self.list)
-	self.list.Bind(wx.EVT_LIST_KEY_DOWN, self.OnKeyDown, self.list)
+	#self.list.Bind(wx.EVT_LIST_ITEM_SELECTED, self.OnItemSelected, self.list)
+	wx.EVT_LIST_ITEM_SELECTED(self, i, self.OnItemSelected)
+	#self.list.Bind(wx.EVT_LIST_KEY_DOWN, self.OnKeyDown, self.list)
+	wx.EVT_KEY_DOWN(self.list, self.OnKeyDown)
 	
 	box.Add(self.list, 0, wx.ALL, 10)
 	
         #========= Add user =============
 	i=wx.NewId()
 	box.Add(wx.Button(self, i, _('Add user')), 0, wx.ALIGN_CENTER)
-	self.Bind(wx.EVT_BUTTON, self.OnAdd, id=i)
+	#self.Bind(wx.EVT_BUTTON, self.OnAdd, id=i)
+	wx.EVT_BUTTON(self, i, self.OnAdd)
 	
 	#========= Ok - Cancel =============
 	b1=wx.BoxSizer(wx.HORIZONTAL)
 	i=wx.NewId()
 	b1.Add(wx.Button(self, i, _('Ok')), 0, wx.ALL, 10)
-	self.Bind(wx.EVT_BUTTON, self.OnOk, id=i)
+	#self.Bind(wx.EVT_BUTTON, self.OnOk, id=i)
+	wx.EVT_BUTTON(self, i, self.OnOk)
 	
 	i=wx.NewId()
 	b1.Add(wx.Button(self, i, _('Cancel')), 0, wx.ALL, 10)
-	self.Bind(wx.EVT_BUTTON, self.OnCancel, id=i)
+	#self.Bind(wx.EVT_BUTTON, self.OnCancel, id=i)
+	wx.EVT_BUTTON(self, i, self.OnCancel)
 	box.Add(b1, 0, wx.ALIGN_CENTER)
 
 	self.SetAutoLayout(True)
@@ -267,34 +279,56 @@
     if os.path.exists(p):
 	users=os.listdir(p)
 	if users != []:
-	    return 'not_first' #user(s) already exist
+	    return 'not_first' #user(s) already exists
     if ask_name():
 	return 'first'
     else:
 	return 'bad_login'
 
 #-------------------------------------------------------
+def check_validname(str):
+    i=0
+    while i<len(str):
+        if ord(str[i])<0x20 or ord(str[i])>0x7f:
+            return False
+        i=i+1
+    return str.isalnum();
+
+#-------------------------------------------------------
 def ask_name(parent=None):
     # nobody, it is first login
+    wx.MessageBox(
+        _("This program is not a reliable contraceptive method.\n"
+        "Neither does it help to prevent sexually transmitted diseases\n"
+        "like HIV/AIDS.\n\nIt is just an electronic means of keeping track\n"
+        "of some of your medical data and extracting some statistical\n"
+        "conclusions from them. You cannot consider this program as a\n"
+        "substitute for your gynecologist in any way."))
     dlg = wx.TextEntryDialog(parent, _('Enter you name:'),_('New user'),'',
 	 style=wx.OK | wx.CANCEL)
     while dlg.ShowModal()==wx.ID_OK:
 	name=dlg.GetValue()
+	name=name.strip()
 	if name != "":
-	    p, f_name=get_f_name(name)
-	    if not os.path.isfile(f_name):
-		d=Ask_Passwd_Dlg(parent)
-		if d.ShowModal()==wx.ID_OK:
-		    cycle.name=name
-		    d.Destroy()
-		    dlg.Destroy()
-		    #self.EndModal(wx.ID_OK)
-		    return True
-		else:
-		    d.Destroy()
-		    continue
+	    if check_validname(name):
+	        #name=name.encode("ascii")
+	        p, f_name=get_f_name(name)
+	        if not os.path.isfile(f_name):
+		    d=Ask_Passwd_Dlg(parent)
+		    if d.ShowModal()==wx.ID_OK:
+		        cycle.name=name
+		        d.Destroy()
+		        dlg.Destroy()
+		        #self.EndModal(wx.ID_OK)
+		        set_color_default()
+		        return True
+		    else:
+		        d.Destroy()
+		        continue
+	        else:
+		    err=name+_(' - already exists!')
 	    else:
-		err=name+_(' - already is exist!')
+	        err=name+_(' - has invalid characters!')
 	else:
 	    err=_('Name must be not EMPTY')
 	d2 = wx.MessageDialog(dlg, err,	_('Error!'), wx.OK |wx.ICON_ERROR )
@@ -326,7 +360,8 @@
 	
 	i=wx.NewId()
 	box.Add(wx.Button(self, i, _('Ok')), 0, wx.ALIGN_CENTER|wx.ALL, 10)
-	self.Bind(wx.EVT_BUTTON, self.OnOk, id=i)
+	#self.Bind(wx.EVT_BUTTON, self.OnOk, id=i)
+	wx.EVT_BUTTON(self, i, self.OnOk)
 	
 	self.SetAutoLayout(True)
         self.SetSizer(box)
@@ -360,15 +395,18 @@
 	b1=wx.BoxSizer(wx.HORIZONTAL)
 	i=wx.NewId()
 	b1.Add(wx.Button(self, i, _('Ok')), 0, wx.ALL, 10)
-	self.Bind(wx.EVT_BUTTON, self.OnOk, id=i)
+	#self.Bind(wx.EVT_BUTTON, self.OnOk, id=i)
+	wx.EVT_BUTTON(self, i, self.OnOk)
 	
 	i=wx.NewId()
 	b1.Add(wx.Button(self, i, _('Cancel')), 0, wx.ALL, 10)
-	self.Bind(wx.EVT_BUTTON, self.OnCancel, id=i)
+	#self.Bind(wx.EVT_BUTTON, self.OnCancel, id=i)
+	wx.EVT_BUTTON(self, i, self.OnCancel)
 	
 	i=wx.NewId()
 	b1.Add(wx.Button(self, i, _('Remove')), 0, wx.ALL, 10)
-	self.Bind(wx.EVT_BUTTON, self.OnRemove, id=i)
+	#self.Bind(wx.EVT_BUTTON, self.OnRemove, id=i)
+	wx.EVT_BUTTON(self, i, self.OnRemove)
 	box.Add(b1, 0, wx.ALIGN_CENTER)
 	
 	self.SetAutoLayout(True)
@@ -413,7 +452,8 @@
 
 	i=wx.NewId()
 	box.Add(wx.Button(self, i, _('Ok')), 0, wx.ALIGN_CENTER|wx.ALL, 10)
-	self.Bind(wx.EVT_BUTTON, self.OnOk, id=i)
+	#self.Bind(wx.EVT_BUTTON, self.OnOk, id=i)
+	wx.EVT_BUTTON(self, i, self.OnOk)
 		
 	self.SetAutoLayout(True)
         self.SetSizer(box)
@@ -448,15 +488,18 @@
 	b1=wx.BoxSizer(wx.HORIZONTAL)
 	i=wx.NewId()
 	b1.Add(wx.Button(self, i, _('Ok')), 0, wx.ALL, 10)
-	self.Bind(wx.EVT_BUTTON, self.OnOk, id=i)
+	#self.Bind(wx.EVT_BUTTON, self.OnOk, id=i)
+	wx.EVT_BUTTON(self, i, self.OnOk)
 
 	i=wx.NewId()
 	b1.Add(wx.Button(self, i, _('By default')), 0, wx.ALL, 10)
-	self.Bind(wx.EVT_BUTTON, self.OnDefault, id=i)
+	#self.Bind(wx.EVT_BUTTON, self.OnDefault, id=i)
+	wx.EVT_BUTTON(self, i, self.OnDefault)
 
 	i=wx.NewId()
 	b1.Add(wx.Button(self, i, _('Cancel')), 0, wx.ALL, 10)
-	self.Bind(wx.EVT_BUTTON, self.OnCancel, id=i)
+	#self.Bind(wx.EVT_BUTTON, self.OnCancel, id=i)
+	wx.EVT_BUTTON(self, i, self.OnCancel)
 	box.Add(b1, 0, wx.ALIGN_CENTER)
 	
 	self.SetAutoLayout(True)
@@ -466,8 +509,9 @@
     def _add(self, box, txt, col):
 	b=wx.BoxSizer(wx.HORIZONTAL)
 	i=self.col_id.index(col)
-        bt=wx.Button(self, i, "", size=wx.Size(15,15))
-	self.Bind(wx.EVT_BUTTON, self.get_colour, id=i)
+	bt=wx.Button(self, i, "", size=wx.Size(15,15))
+	#self.Bind(wx.EVT_BUTTON, self.get_colour, id=i)
+	wx.EVT_BUTTON(self, i, self.get_colour)
 	bt.SetBackgroundColour(self.col_set[col])
 	self.buttons.update({i:bt})
 	b.Add(bt, 0, wx.LEFT|wx.RIGHT,10)
@@ -490,15 +534,15 @@
 	self.EndModal(wx.ID_OK)
 
     def OnDefault(self, event):
-	self.col_set = {'begin':wx.NamedColour('red'),
-	    'prog begin':wx.NamedColour('pink'),
+	self.col_set = {'begin':wx.NamedColour('RED'),
+	    'prog begin':wx.NamedColour('PINK'),
 	    'conception':wx.NamedColour('MAGENTA'),
-	    'safe sex':wx.NamedColour('wheat'),
-	    'fertile':wx.NamedColour('green yellow'),
+	    'safe sex':wx.NamedColour('WHEAT'),
+	    'fertile':wx.NamedColour('GREEN YELLOW'),
 	    'ovule':wx.NamedColour('SPRING GREEN'),
-	    '1-st tablet':wx.NamedColour('gold'),
-	    'pause':wx.NamedColour('light blue'),
-	    'next 1-st tablet':wx.NamedColour('pink')}
+	    '1-st tablet':wx.NamedColour('GOLD'),
+	    'pause':wx.NamedColour('LIGHT BLUE'),
+	    'next 1-st tablet':wx.NamedColour('PINK')}
 	for item in self.col_id:
 	    self.buttons[self.col_id.index(item)].SetBackgroundColour(self.col_set[item])
 
