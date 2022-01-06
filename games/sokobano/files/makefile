# Makefile to rebuild a limited subset of *.java files (only those that
# we patch in the port).

empty:=
space:=$(empty) $(empty)

JAR?=		jar
JAVAC?=		javac -encoding ISO-8859-1 -XDenableSunApiLintControl
BUILD_CLASSPATHS=	\
		.. $(LOCALBASE)/share/java/classes/lwjgl/lwjgl.jar

CLASS_FILES=	$(JAVA_FILES:.java=.class)
JAVA_FILES=	logic/ConfigManager.java \
		logic/LevelManager.java \
		logic/LevelSetManager.java \
		logic/PlayerManager.java

BINDIR=		../../bin
VPATH=		$(BINDIR)/gdi1sokoban

$(CLASS_FILES): %.class: %.java
	JAVA_VERSION=$(JAVA_VERSION) $(JAVAC) \
		-d $(BINDIR) \
		-cp $(subst $(space),:,$(BUILD_CLASSPATHS)) \
		$<

RUNTIME_CLASSPATHS=	\
	$(LOCALBASE)/share/java/classes/lwjgl/lwjgl.jar \
	$(LOCALBASE)/share/java/classes/lwjgl/lwjgl_util.jar \
	$(LOCALBASE)/share/java/classes/jmf.jar

manifest-addition:
	@echo 'Class-Path: $(RUNTIME_CLASSPATHS)' > $@
	@echo 'Main-Class: gdi1sokoban.Application' >> $@

Sokobano.jar: manifest-addition $(CLASS_FILES)
	$(JAR) cfm $(BINDIR)/$@ $< -C $(BINDIR) gdi1sokoban

all: Sokobano.jar

.PHONY: all
