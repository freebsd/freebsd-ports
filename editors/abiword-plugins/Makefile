# New ports collection makefile for:	abiword-plugins
# Date created:				13 June 2004
# Whom:					FreeBSD GNOME Team <gnome@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/editors/abiword-plugins/Makefile,v 1.18 2006/07/18 12:45:43 ahze Exp $
#

PORTNAME=	abiword-plugins
PORTVERSION=	2.6.8
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://www.abisource.com/downloads/%SUBDIR%/${PORTVERSION}/source/
MASTER_SITE_SUBDIR=	abiword
DIST_SUBDIR=	AbiWord
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.gz \
		${PORTNAME:S/-plugins//}-${PORTVERSION}.tar.gz

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Multi-plugins for AbiWord

BUILD_DEPENDS=	abiword:${PORTSDIR}/editors/abiword
RUN_DEPENDS=	abiword:${PORTSDIR}/editors/abiword

USE_GMAKE=	yes
USE_GNOME=	gnometarget gtk20
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-all \
		--with-abiword=${WRKDIR}/${PORTNAME:S/-plugins//}-${PORTVERSION}
MAKEFILE=	GNUmakefile

ABIVERSION=	2.6
PLIST_SUB+=	ABIVERSION=${ABIVERSION}

.if !defined(WITHOUT_OPTIONS)
.include "${.CURDIR}/options"
.endif

.include <bsd.port.pre.mk>

# NOTE: Please, keep those knobs in the ABC's order.

.if defined(WITH_AIKSAURUS) || defined(PACKAGE_BUILDING)
LIB_DEPENDS+=		AiksaurusGTK-1.2.0:${PORTSDIR}/textproc/aiksaurus-gtk
CONFIGURE_ARGS+=	--enable-aiksaurus
PLIST_SUB+=		AIKSAURUS:=""
.else
CONFIGURE_ARGS+=	--disable-aiksaurus
PLIST_SUB+=		AIKSAURUS:="@comment "
.endif

.if !defined(WITHOUT_APPLIX)
CONFIGURE_ARGS+=	--enable-applix
PLIST_SUB+=		APPLIX:=""
.else
CONFIGURE_ARGS+=	--disable-applix
PLIST_SUB+=		APPLIX:="@comment "
.endif

.if !defined(WITHOUT_BABELFISH)
CONFIGURE_ARGS+=	--enable-babelfish
PLIST_SUB+=		BABELFISH:=""
.else
CONFIGURE_ARGS+=	--disable-babelfish
PLIST_SUB+=		BABELFISH:="@comment "
.endif

.if !defined(WITHOUT_BMP)
CONFIGURE_ARGS+=	--enable-bmp
PLIST_SUB+=		BMP:=""
.else
CONFIGURE_ARGS+=	--disable-bmp
PLIST_SUB+=		BMP:="@comment "
.endif

.if defined(WITH_CLARISWORKS) # Need to be tested
CONFIGURE_ARGS+=	--enable-clarisworks
PLIST_SUB+=		CLARISWORKS:=""
.else
CONFIGURE_ARGS+=	--disable-clarisworks
PLIST_SUB+=		CLARISWORKS:="@comment "
.endif

.if !defined(WITHOUT_COMMAND)
CONFIGURE_ARGS+=	--enable-abicommand
PLIST_SUB+=		COMMAND:=""
.else
CONFIGURE_ARGS+=	--disable-abicommand
PLIST_SUB+=		COMMAND:="@comment "
.endif

.if defined(WITH_DOCBOOK) # Need to be tested
CONFIGURE_ARGS+=	--enable-docbook
PLIST_SUB+=		DOCBOOK:=""
.else
CONFIGURE_ARGS+=	--disable-docbook
PLIST_SUB+=		DOCBOOK:="@comment "
.endif

.if defined(WITH_EML) # Need to be tested
CONFIGURE_ARGS+=	--enable-eml
PLIST_SUB+=		EML:=""
.else
CONFIGURE_ARGS+=	--disable-eml
PLIST_SUB+=		EML:="@comment "
.endif

.if !defined(WITHOUT_FREETRANSLATION)
CONFIGURE_ARGS+=	--enable-freetranslation
PLIST_SUB+=		FREETRANSLATION:=""
.else
CONFIGURE_ARGS+=	--disable-freetranslation
PLIST_SUB+=		FREETRANSLATION:="@comment "
.endif

.if defined(WITH_GDICT)
RUN_DEPENDS+=		gnome-dictionary:${PORTSDIR}/deskutils/gnome-utils
CONFIGURE_ARGS+=	--enable-gdict
PLIST_SUB+=		GDICT:=""
.else
CONFIGURE_ARGS+=	--disable-gdict
PLIST_SUB+=		GDICT:="@comment "
.endif

.if !defined(WITHOUT_GOOGLE)
CONFIGURE_ARGS+=	--enable-google
PLIST_SUB+=		GOOGLE:=""
.else
CONFIGURE_ARGS+=	--disable-google
PLIST_SUB+=		GOOGLE:="@comment "
.endif

.if defined(WITH_GRAMMAR) || defined(PACKAGE_BUILDING)
LIB_DEPENDS+=		link-grammar.4:${PORTSDIR}/textproc/link-grammar
CONFIGURE_ARGS+=	--enable-abigrammar
PLIST_SUB+=		GRAMMAR:=""
.else
CONFIGURE_ARGS+=	--disable-abigrammar
PLIST_SUB+=		GRAMMAR:="@comment "
.endif

.if defined(WITH_HANCOM) # Need to be tested
CONFIGURE_ARGS+=	--enable-hancom
PLIST_SUB+=		HANCOM:=""
.else
CONFIGURE_ARGS+=	--disable-hancom
PLIST_SUB+=		HANCOM:="@comment "
.endif

.if defined(WITH_HRTEXT) # Need to be tested
CONFIGURE_ARGS+=	--enable-hrtext
PLIST_SUB+=		HRTEXT:=""
.else
CONFIGURE_ARGS+=	--disable-hrtext
PLIST_SUB+=		HRTEXT:="@comment "
.endif

.if defined(WITH_JPEG) || defined(PACKAGE_BUILDING)
CONFIGURE_ARGS+=	--enable-jpeg
PLIST_SUB+=		JPEG:=""
.else
CONFIGURE_ARGS+=	--disable-jpeg
PLIST_SUB+=		JPEG:="@comment "
.endif

.if defined(WITH_LATEX) # Need to be tested
CONFIGURE_ARGS+=	--enable-latex
PLIST_SUB+=		LATEX:=""
.else
CONFIGURE_ARGS+=	--disable-latex
PLIST_SUB+=		LATEX:="@comment "
.endif

.if defined(WITH_MATHVIEW) || defined(PACKAGE_BUILDING)
LIB_DEPENDS+=		mathview_backend_gtk.8:${PORTSDIR}/x11-toolkits/gtkmathview
CONFIGURE_ARGS+=	--enable-abimathview
PLIST_SUB+=		MATHVIEW:=""
.else
CONFIGURE_ARGS+=	--disable-abimathview
PLIST_SUB+=		MATHVIEW:="@comment "
.endif

.if !defined(WITHOUT_MSWRITE)
CONFIGURE_ARGS+=	--enable-mswrite
PLIST_SUB+=		MSWRITE:=""
.else
CONFIGURE_ARGS+=	--disable-mswrite
PLIST_SUB+=		MSWRITE:="@comment "
.endif

.if defined(WITH_NROFF) # Need to be tested
CONFIGURE_ARGS+=	--enable-nroff
PLIST_SUB+=		NROFF:=""
.else
CONFIGURE_ARGS+=	--disable-nroff
PLIST_SUB+=		NROFF:="@comment "
.endif

.if defined(WITH_OPENDOCUMENT) || defined(PACKAGE_BUILDING)
USE_GNOME+=		libgsf
CONFIGURE_ARGS+=	--enable-OpenDocument
PLIST_SUB+=		OPENDOCUMENT:=""
.else
CONFIGURE_ARGS+=	--disable-OpenDocument
PLIST_SUB+=		OPENDOCUMENT:="@comment "
.endif

.if defined(WITH_OPENWRITER) || defined(PACKAGE_BUILDING)
USE_GNOME+=		libgsf
CONFIGURE_ARGS+=	--enable-OpenWriter
PLIST_SUB+=		OPENWRITER:=""
.else
CONFIGURE_ARGS+=	--disable-OpenWriter
PLIST_SUB+=		OPENWRITER:="@comment "
.endif

.if defined(WITH_OPENXML) || defined(PACKAGE_BUILDING)
BUILD_DEPENDS+=		${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost-libs
USE_GNOME+=		libgsf
CONFIGURE_ARGS+=	--enable-OpenXML
PLIST_SUB+=		OPENXML:=""
.else
CONFIGURE_ARGS+=	--disable-OpenXML \
			--without-boost
PLIST_SUB+=		OPENXML:="@comment "
.endif

.if defined(WITH_PDB) # Need to be tested
CONFIGURE_ARGS+=	--enable-pdb
PLIST_SUB+=		PDB:=""
.else
CONFIGURE_ARGS+=	--disable-pdb
PLIST_SUB+=		PDB:="@comment "
.endif

.if defined(WITH_PSION)
LIB_DEPENDS+=		psiconv.10:${PORTSDIR}/converters/psiconv
CONFIGURE_ARGS+=	--with-psion
PLIST_SUB+=		PSION:=""
.else
CONFIGURE_ARGS+=	--disable-psion
PLIST_SUB+=		PSION:="@comment "
.endif

.if defined(WITH_SDW)
USE_GNOME+=		libgsf
CONFIGURE_ARGS+=	--enable-sdw
PLIST_SUB+=		SDW:=""
.else
CONFIGURE_ARGS+=	--disable-sdw
PLIST_SUB+=		SDW:="@comment "
.endif

.if !defined(WITHOUT_SHELL)
CONFIGURE_ARGS+=	--enable-shell
PLIST_SUB+=		SHELL:=""
.else
CONFIGURE_ARGS+=	--disable-shell
PLIST_SUB+=		SHELL:="@comment "
.endif

.if defined(WITH_T602) # Need to be tested
CONFIGURE_ARGS+=	--enable-t602
PLIST_SUB+=		T602:=""
.else
CONFIGURE_ARGS+=	--disable-t602
PLIST_SUB+=		T602:="@comment "
.endif

.if !defined(WITHOUT_URLDICT)
CONFIGURE_ARGS+=	--enable-urldict
PLIST_SUB+=		URLDICT:=""
.else
CONFIGURE_ARGS+=	--disable-urldict
PLIST_SUB+=		URLDICT:="@comment "
.endif

.if !defined(WITHOUT_WIKIPEDIA)
CONFIGURE_ARGS+=	--enable-wikipedia
PLIST_SUB+=		WIKIPEDIA:=""
.else
CONFIGURE_ARGS+=	--disable-wikipedia
PLIST_SUB+=		WIKIPEDIA:="@comment "
.endif

.if defined(WITH_WMF) || defined(PACKAGE_BUILDING)
LIB_DEPENDS+=		wmf.2:${PORTSDIR}/graphics/libwmf
CONFIGURE_ARGS+=	--enable-wmf
PLIST_SUB+=		WMF:=""
.else
CONFIGURE_ARGS+=	--disable-wmf
PLIST_SUB+=		WMF:="@comment "
.endif

.if defined(WITH_WORDPERFECT) || defined(PACKAGE_BUILDING)
LIB_DEPENDS+=		wps-0.1.1:${PORTSDIR}/textproc/libwps
CONFIGURE_ARGS+=	--enable-wordperfect
PLIST_SUB+=		WORDPERFECT:=""
.else
CONFIGURE_ARGS+=	--disable-wordperfect
PLIST_SUB+=		WORDPERFECT:="@comment "
.endif

.if !defined(WITHOUT_XSLFO)
CONFIGURE_ARGS+=	--enable-xsl-fo
PLIST_SUB+=		XSLFO:=""
.else
CONFIGURE_ARGS+=	--disable-xsl-fo
PLIST_SUB+=		XSLFO:="@comment "
.endif

#.if ${HAVE_GNOME:Mnautilus2}!="" && ${HAVE_GNOME:Mlibgnomeprintui}!=""
#USE_GNOME+=		nautilus2 libgnomeprintui
#CONFIGURE_ARGS+=	--enable-gnome
#.endif

.if ${HAVE_GNOME:Mlibrsvg2}!=""
CONFIGURE_ARGS+=	--enable-librsvg
PLIST_SUB+=		SVG:=""
.else
CONFIGURE_ARGS+=	--disable-librsvg
PLIST_SUB+=		SVG:="@comment "
.endif

.if defined(WITHOUT_OPTIONS)
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
.if !defined(WITH_GRAMMAR)
	@${ECHO_MSG} "WITH_GRAMMAR=yes	Allows AbiWord to be Grammar checked."
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
.if !defined(WITH_MATHVIEW)
	@${ECHO_MSG} "WITH_MATHVIEW=yes	Enables AbiWord to embed some maths."
.endif
.if !defined(WITH_NROFF)
	@${ECHO_MSG} "WITH_NROFF=yes		Nroff/Man file format."
.endif
.if !defined(WITH_OPENDOCUMENT)
	@${ECHO_MSG} "WITH_OPENDOCUMENT=yes	Import/export OpenDocument files."
.endif
.if !defined(WITH_OPENWRITER)
	@${ECHO_MSG} "WITH_OPENWRITER=yes	Import/export OpenOffice files."
.endif
.if !defined(WITH_OPENXML)
	@${ECHO_MSG} "WITH_OPENXML=yes	Allow AbiWord to read OpenXML .docx files."
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
.endif # WITH_OPTIONS

.include <bsd.port.post.mk>
