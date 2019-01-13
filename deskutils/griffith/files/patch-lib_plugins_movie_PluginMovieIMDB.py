--- lib/plugins/movie/PluginMovieIMDB.py.orig	2019-01-10 08:53:18 UTC
+++ lib/plugins/movie/PluginMovieIMDB.py
@@ -43,7 +43,7 @@ class Plugin(movie.Movie):
 
     def initialize(self):
         self.cast_page = self.open_page(url=self.url + '/fullcredits')
-        self.plot_page = self.open_page(url=self.url + '/plotsummary')
+        self.plot_page = self.open_page(url=self.url)
         self.comp_page = self.open_page(url=self.url + '/companycredits')
         self.tagl_page = self.open_page(url=self.url + '/taglines')
 
@@ -78,17 +78,8 @@ class Plugin(movie.Movie):
             self.director = self.director[0:len(self.director) - 2]
 
     def get_plot(self):
-        self.plot = gutils.regextrim(self.page, 'itemprop="description"', '<')
-        self.plot = gutils.after(self.plot, '>')
-        elements = self.plot_page.split('<p class="plotpar">')
-        if len(elements) < 2:
-            elements = re.split('<li class="(?:odd|even)">', self.plot_page)
-        if len(elements) > 1:
-            self.plot = self.plot + '\n\n'
-            elements[0] = ''
-            for element in elements[1:]:
-                if element != '':
-                    self.plot = self.plot + gutils.strip_tags(gutils.before(element, '</a>')) + '\n\n'
+        self.plot = gutils.trim(self.page, '<h2>Storyline</h2>', '</span>')
+        self.plot = gutils.after(self.plot, '<span>    ')
 
     def get_year(self):
         self.year = gutils.trim(self.page, '<a href="/year/', '</a>')
