# New ports collection makefile for:	abiword-plugins
# Date created:				13 June 2004
# Whom:					FreeBSD GNOME Team <gnome@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	abiword
PORTVERSION=	2.3.0
CATEGORIES=	editors
MASTER_SITES=	http://www.abisource.com/downloads/%SUBDIR%/${PORTVERSION}/source/
MASTER_SITE_SUBDIR=	abiword
PKGNAMESUFFIX=	-plugins-devel
DIST_SUBDIR=	AbiWord

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Multi-plugins for AbiWord

BUILD_DEPENDS=	AbiWord-2.4:${PORTSDIR}/editors/abiword
RUN_DEPENDS=	AbiWord-2.4:${PORTSDIR}/editors/abiword

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget gtk20
WANT_GNOME=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_LIBTOOL_VER=15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-all
MAKEFILE=	GNUmakefile

WRKSRC=		${WRKDIR}/abiword-${PORTVERSION}/abiword-plugins
MD5_FILE=	${.CURDIR}/../abiword/distinfo

ABIVERSION=	2.4
PLIST_SUB+=	ABIVERSION=${ABIVERSION}

# NOTE: Please, keep those knobs in the ABC's order.

.if defined(WITH_AIKSAURUS) || defined(PACKAGE_BUILDING)
LIB_DEPENDS+=		AiksaurusGTK-1.2.0:${PORTSDIR}/textproc/aiksaurus-gtk
CONFIGURE_ARGS+=	--enable-aiksaurus
PLIST_SUB+=		AIKSAURUS:=""
.else
PLIST_SUB+=		AIKSAURUS:="@comment "
.endif

.if !defined(WITHOUT_APPLIX)
CONFIGURE_ARGS+=	--enable-applix
PLIST_SUB+=		APPLIX:=""
.else
PLIST_SUB+=		APPLIX:="@comment "
.endif

.if !defined(WITHOUT_BABELFISH)
CONFIGURE_ARGS+=	--enable-babelfish
PLIST_SUB+=		BABELFISH:=""
.else
PLIST_SUB+=		BABELFISH:="@comment "
.endif

.if !defined(WITHOUT_BMP)
CONFIGURE_ARGS+=	--enable-bmp
PLIST_SUB+=		BMP:=""
.else
PLIST_SUB+=		BMP:="@comment "
.endif

.if !defined(WITHOUT_BZ2ABW)
CONFIGURE_ARGS+=	--enable-bz2abw \
			--with-bzip2=/usr
PLIST_SUB+=		BZ2ABW:=""
.else
PLIST_SUB+=		BZ2ABW:="@comment "
.endif

.if defined(WITH_CLARISWORKS) # Need to be tested
CONFIGURE_ARGS+=	--enable-clarisworks
PLIST_SUB+=		CLARISWORKS:=""
.else
PLIST_SUB+=		CLARISWORKS:="@comment "
.endif

.if !defined(WITHOUT_COMMAND)
CONFIGURE_ARGS+=	--enable-abicommand
PLIST_SUB+=		COMMAND:=""
.else
PLIST_SUB+=		COMMAND:="@comment "
.endif

.if defined(WITH_DOCBOOK) # Need to be tested
CONFIGURE_ARGS+=	--enable-docbook
PLIST_SUB+=		DOCBOOK:=""
.else
PLIST_SUB+=		DOCBOOK:="@comment "
.endif

.if defined(WITH_EML) # Need to be tested
CONFIGURE_ARGS+=	--enable-eml
PLIST_SUB+=		EML:=""
.else
PLIST_SUB+=		EML:="@comment "
.endif

.if !defined(WITHOUT_FREETRANSLATION)
CONFIGURE_ARGS+=	--enable-freetranslation
PLIST_SUB+=		FREETRANSLATION:=""
.else
PLIST_SUB+=		FREETRANSLATION:="@comment "
.endif

.if defined(WITH_GDICT)
RUN_DEPENDS+=		gnome-dictionary:${PORTSDIR}/deskutils/gnomeutils2
CONFIGURE_ARGS+=	--enable-gdict
PLIST_SUB+=		GDICT:=""
.else
PLIST_SUB+=		GDICT:="@comment "
.endif

.if !defined(WITHOUT_GOOGLE)
CONFIGURE_ARGS+=	--enable-google
PLIST_SUB+=		GOOGLE:=""
.else
PLIST_SUB+=		GOOGLE:="@comment "
.endif

.if defined(WITH_HANCOM) # Need to be tested
CONFIGURE_ARGS+=	--enable-hancom
PLIST_SUB+=		HANCOM:=""
.else
PLIST_SUB+=		HANCOM:="@comment "
.endif

.if defined(WITH_HRTEXT) # Need to be tested
CONFIGURE_ARGS+=	--enable-hrtext
PLIST_SUB+=		HRTEXT:=""
.else
PLIST_SUB+=		HRTEXT:="@comment "
.endif

.if defined(WITH_JPEG) || defined(PACKAGE_BUILDING)
CONFIGURE_ARGS+=	--enable-jpeg
PLIST_SUB+=		JPEG:=""
.else
PLIST_SUB+=		JPEG:="@comment "
.endif

.if defined(WITH_LATEX) # Need to be tested
CONFIGURE_ARGS+=	--enable-latex
PLIST_SUB+=		LATEX:=""
.else
PLIST_SUB+=		LATEX:="@comment "
.endif

.if !defined(WITHOUT_MSWRITE)
CONFIGURE_ARGS+=	--enable-mswrite
PLIST_SUB+=		MSWRITE:=""
.else
PLIST_SUB+=		MSWRITE:="@comment "
.endif

.if defined(WITH_NROFF) # Need to be tested
CONFIGURE_ARGS+=	--enable-nroff
PLIST_SUB+=		NROFF:=""
.else
PLIST_SUB+=		NROFF:="@comment "
.endif

.if defined(WITH_OPENWRITER) || defined(PACKAGE_BUILDING)
USE_GNOME+=		libgsf
CONFIGURE_ARGS+=	--enable-OpenWriter
PLIST_SUB+=		OPENWRITER:=""
.else
PLIST_SUB+=		OPENWRITER:="@comment "
.endif

.if defined(WITH_PDB) # Need to be tested
CONFIGURE_ARGS+=	--enable-pdb
PLIST_SUB+=		PDB:=""
.else
PLIST_SUB+=		PDB:="@comment "
.endif

.if defined(WITH_PSION)
LIB_DEPENDS+=		psiconv.10:${PORTSDIR}/converters/psiconv
CONFIGURE_ARGS+=	--with-psion
PLIST_SUB+=		PSION:=""
.else
PLIST_SUB+=		PSION:="@comment "
.endif

.if defined(WITH_SDW)
USE_GNOME+=		libgsf
CONFIGURE_ARGS+=	--enable-sdw
PLIST_SUB+=		SDW:=""
.else
PLIST_SUB+=		SDW:="@comment "
.endif

.if !defined(WITHOUT_SHELL)
CONFIGURE_ARGS+=	--enable-shell
PLIST_SUB+=		SHELL:=""
.else
PLIST_SUB+=		SHELL:="@comment "
.endif

.if defined(WITH_T602) # Need to be tested
CONFIGURE_ARGS+=	--enable-t602
PLIST_SUB+=		T602:=""
.else
PLIST_SUB+=		T602:="@comment "
.endif

.if !defined(WITHOUT_URLDICT)
CONFIGURE_ARGS+=	--enable-urldict
PLIST_SUB+=		URLDICT:=""
.else
PLIST_SUB+=		URLDICT:="@comment "
.endif

.if !defined(WITHOUT_WIKIPEDIA)
CONFIGURE_ARGS+=	--enable-wikipedia
PLIST_SUB+=		WIKIPEDIA:=""
.else
PLIST_SUB+=		WIKIPEDIA:="@comment "
.endif

.if defined(WITH_WMF) || defined(PACKAGE_BUILDING)
LIB_DEPENDS+=		wmf.2:${PORTSDIR}/graphics/libwmf
CONFIGURE_ARGS+=	--enable-wmf
PLIST_SUB+=		WMF:=""
.else
PLIST_SUB+=		WMF:="@comment "
.endif

.if defined(WITH_WORDPERFECT) || defined(PACKAGE_BUILDING)
LIB_DEPENDS+=		wpd-0.8.8:${PORTSDIR}/textproc/libwpd
CONFIGURE_ARGS+=	--enable-wordperfect
PLIST_SUB+=		WORDPERFECT:=""
.else
PLIST_SUB+=		WORDPERFECT:="@comment "
.endif

.if !defined(WITHOUT_XSLFO)
CONFIGURE_ARGS+=	--enable-xsl-fo
PLIST_SUB+=		XSLFO:=""
.else
PLIST_SUB+=		XSLFO:="@comment "
.endif

.include <bsd.port.pre.mk>

#.if ${HAVE_GNOME:Mnautilus2}!="" && ${HAVE_GNOME:Mlibgnomeprintui}!=""
#USE_GNOME+=		nautilus2 libgnomeprintui
#CONFIGURE_ARGS+=	--enable-gnome
#.endif

.if ${HAVE_GNOME:Mlibrsvg2}!=""
CONFIGURE_ARGS+=	--enable-librsvg
PLIST_SUB+=		SVG:=""
.else
PLIST_SUB+=		SVG:="@comment "
.endif

pre-everything::
	@${ECHO_MSG} "You may specify the following on the command line:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "To enable plugins:"
	@${ECHO_MSG} "========================================================"
.if !defined(WITH_AIKSAURUS)
	@${ECHO_MSG} "WITH_AIKSAURUS=yes	English language thesaurus."
.endif
.if !defined(WITH_CLARISWORKS)
	@${ECHO_MSG} "WITH_CLARISWORKS=yes	Import/Export Clarisworks files."
.endif
.if !defined(WITH_DOCBOOK)
	@${ECHO_MSG} "WITH_DOCBOOK=yes	Import/export Docbook files."
.endif
.if !defined(WITH_EML)
	@${ECHO_MSG} "WITH_EML=yes		Import/export as MS Outlook Email files."
.endif
.if !defined(WITH_GDICT)
	@${ECHO_MSG} "WITH_GDICT=yes		Look up definitions of selected text."
.endif
.if !defined(WITH_HANCOM)
	@${ECHO_MSG} "WITH_HANCOM=yes		Hancom Word Importer. Only does text."
.endif
.if !defined(WITH_HRTEXT)
	@${ECHO_MSG} "WITH_HRTEXT=yes		Export text with \"newsgroup\" markup."
.endif
.if !defined(WITH_JPEG)
	@${ECHO_MSG} "WITH_JPEG=yes		View JPEG Images."
.endif
.if !defined(WITH_LATEX)
	@${ECHO_MSG} "WITH_LATEX=yes		LaTeX export."
.endif
.if !defined(WITH_NROFF)
	@${ECHO_MSG} "WITH_NROFF=yes		Nroff/Man file format."
.endif
.if !defined(WITH_OPENWRITER)
	@${ECHO_MSG} "WITH_OPENWRITER=yes	Import/export OpenOffice files."
.endif
.if !defined(WITH_PDB)
	@${ECHO_MSG} "WITH_PDB=yes		Import/export Palm Database files."
.endif
.if !defined(WITH_PSION)
	@${ECHO_MSG} "WITH_PSION=yes		Import/export Psion files."
.endif
.if !defined(WITH_SDW)
	@${ECHO_MSG} "WITH_SDW=yes		Import StarOffice 5.x files."
.endif
.if !defined(WITH_T602)
	@${ECHO_MSG} "WITH_T602=yes		Import T602 files."
.endif
.if !defined(WITH_WMF)
	@${ECHO_MSG} "WITH_WMF=yes		View Windows Metafiles."
.endif
.if !defined(WITH_WORDPERFECT)
	@${ECHO_MSG} "WITH_WORDPERFECT=yes	Import/export Wordperfect files."
.endif
	@${ECHO_MSG} ""
	@${ECHO_MSG} "To disable plugins:"
	@${ECHO_MSG} "========================================================"
.if !defined(WITH_APPLIX)
	@${ECHO_MSG} "WITHOUT_APPLIX=yes	Import/Export Applix Word files."
.endif
.if !defined(WITHOUT_BABELFISH)
	@${ECHO_MSG} "WITHOUT_BABELFISH=yes	Translate selected text."
.endif
.if !defined(WITHOUT_BMP)
	@${ECHO_MSG} "WITHOUT_BMP=yes		View Bitmap Images."
.endif
.if !defined(WITHOUT_BZ2ABW)
	@${ECHO_MSG} "WITHOUT_BZ2ABW=yes	Import/Export BZ2 compressed AbiWord files."
.endif
.if !defined(WITHOUT_COMMAND)
	@${ECHO_MSG} "WITHOUT_COMMAND=yes	Allows command line control of AbiWord."
.endif
.if !defined(WITHOUT_FREETRANSLATION)
	@${ECHO_MSG} "WITHOUT_FREETRANSLATION=yes	Translate selected text."
.endif
.if !defined(WITHOUT_GOOGLE)
	@${ECHO_MSG} "WITHOUT_GOOGLE=yes	Search Google for your selected text."
.endif
.if !defined(WITHOUT_MSWRITE)
	@${ECHO_MSG} "WITHOUT_MSWRITE=yes	Import MSWrite files."
.endif
.if !defined(WITHOUT_SHELL)
	@${ECHO_MSG} "WITHOUT_SHELL=yes	Execute shell commands from within AbiWord."
.endif
.if !defined(WITHOUT_URLDICT)
	@${ECHO_MSG} "WITHOUT_URLDICT=yes	Url dictionary."
.endif
.if !defined(WITHOUT_WIKIPEDIA)
	@${ECHO_MSG} "WITHOUT_WIKIPEDIA=yes	Search online encyclopedia for selected text."
.endif
.if !defined(WITHOUT_XSLFO)
	@${ECHO_MSG} "WITHOUT_XSLFO=yes	Import/export XSL-FO."
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|[$$]abi_plugin_source/../wv|${LOCALBASE}/include/wv|g' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
