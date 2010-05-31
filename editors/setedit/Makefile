# New ports collection makefile for:	setedit
# Date created:				29 September 2005
# Whom:					Sten Feldman
#
# $FreeBSD$

PORTNAME=	setedit
PORTVERSION=	0.5.4
PORTREVISION=	3
CATEGORIES=	editors
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-unix/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	exile@chamber.ee
COMMENT=	Programmer's editor with a nice Text User Interface (TUI)

LIB_DEPENDS=	rhtv.2:${PORTSDIR}/devel/rhtvision

HAS_CONFIGURE=	yes
CONFIGURE_ENV=	LOCALBASE="${LOCALBASE}"
USE_PERL5_BUILD=yes
USE_GMAKE=	yes

MAN1=		setedit.1 infview.1
INFO=		setedit sdg infview

OPTIONS=	BZIP2 "Support for bzip2" On \
		CALC "Enable internal calculator" On \
		CALENDAR "Enable internal calendar" On \
		NLS "International support (requires intl)" On \
		AALIB "Support for AAlib" Off \
		ELECTRIC "Compile with Electric Fence memory debugger" Off

WRKSRC=		${WRKDIR}/${PORTNAME}

CONFIGURE_ARGS=	--prefix=${PREFIX} --without-mp3

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
BROKEN=		Does not compile
.endif

.if defined(WITHOUT_BZIP2)
CONFIGURE_ARGS+=	--no-bzip2
.else
CONFIGURE_ARGS+=	--bzip2
.endif

.if defined(WITHOUT_CALC)
CONFIGURE_ARGS+=	--without-calc
.endif

.if defined(WITHOUT_CALENDAR)
CONFIGURE_ARGS+=	--without-calendar
.endif

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--no-intl
.else
USE_GETTEXT=	yes
PLIST_FILES=	share/locale/es/LC_MESSAGES/setedit.mo \
		share/locale/de/LC_MESSAGES/setedit.mo
.endif

.if defined(WITH_AALIB)
LIB_DEPENDS+=	aa.1:${PORTSDIR}/graphics/aalib
CONFIGURE_ARGS+=	--with-aa
.else
CONFIGURE_ARGS+=	--without-aa
.endif

.if defined(WITH_ELECTRIC)
LIB_DEPENDS+=	efence.0:${PORTSDIR}/devel/ElectricFence
CONFIGURE_ARGS+=	--with-efence
.endif

post-build:
	@${ECHO_CMD} "Packing documentation..."
	@cd ${WRKSRC}/doc ; \
	${CP} editor.inf setedit.info ; \
	${CP} sdg.inf sdg.info ; \
	${CP} infeng.inf infview.info ; \
	${CP} editor.txt setedit.txt ; ${GZIP_CMD} setedit.txt ; \
	${CP} infeng.txt infview.txt ; ${GZIP_CMD} infview.txt ; \
	${CP} setedit.man setedit.1 ; \
	${CP} infview.man infview.1 ; \
	${GZIP_CMD} sdg.txt

do-install:
	@${MKDIR} ${DATADIR}
	@${MKDIR} ${DATADIR}/eterm
	@${MKDIR} ${DATADIR}/eterm/Setedit
	${INSTALL_PROGRAM} ${WRKSRC}/makes/editor.exe ${PREFIX}/bin/setedit
	${INSTALL_PROGRAM} ${WRKSRC}/makes/infview.exe ${PREFIX}/bin/infview
	${INSTALL_DATA} ${WRKSRC}/cfgfiles/eterm/Setedit/MAIN ${DATADIR}/eterm/Setedit
	${INSTALL_DATA} ${WRKSRC}/cfgfiles/eterm/Setedit/Setedit.menu ${DATADIR}/eterm/Setedit
	${INSTALL_DATA} ${WRKSRC}/cfgfiles/eterm/readme.txt ${DATADIR}/eterm
	${INSTALL_DATA} ${WRKSRC}/cfgfiles/eterm/xterm-eterm-tv ${DATADIR}/eterm
	${INSTALL_DATA} ${WRKSRC}/cfgfiles/asm51.pmc ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/cfgfiles/clippmac.pmc ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/cfgfiles/cpmacros.pmc ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/cfgfiles/htmlmac.pmc ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/cfgfiles/perlmac.pmc ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/cfgfiles/pmacros.pmc ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/cfgfiles/wmlmac.pmc ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/cfgfiles/syntaxhl.shl ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/cfgfiles/editor.tip ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/cfgfiles/simple.tip ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/BTerminus.sft ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/Terminus.sft ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/XFont.sft ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/antique.sft ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/boxround.sft ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/cntdown.sft ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/medieval.sft ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/ocr.sft ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/roman.sft ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/rombios.sft ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/thin.sft ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/sdg/txhgen-i.htm ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/sdg/txhgen-i.txi ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/sdg/txhgen-i.txt ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/sdg/html.frt ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/sdg/multi.frt ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/sdg/tex.frt ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/cfgfiles/menubind.smn ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/cfgfiles/redmond.smn ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/cfgfiles/examples.slp ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/cfgfiles/macros.slp ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/cfgfiles/errors.cle ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/doc/readme.1st ${DATADIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ${MAN1} ${MANPREFIX}/man/man1
.if !defined(WITHOUT_NLS)
	${INSTALL_DATA} ${WRKSRC}/internac/es.mo ${PREFIX}/share/locale/es/LC_MESSAGES/setedit.mo
	${INSTALL_DATA} ${WRKSRC}/internac/de.mo ${PREFIX}/share/locale/de/LC_MESSAGES/setedit.mo
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/examples
	@${MKDIR} ${DOCSDIR}/tag_imgs
	${INSTALL_DATA} ${WRKSRC}/distrib/examples/tvrc ${DOCSDIR}/examples
	${INSTALL_DATA} ${WRKSRC}/distrib/examples/examp1.dst ${DOCSDIR}/examples
	${INSTALL_DATA} ${WRKSRC}/distrib/examples/examp1.epr ${DOCSDIR}/examples
	${INSTALL_DATA} ${WRKSRC}/distrib/examples/test1.cc ${DOCSDIR}/examples
	${INSTALL_DATA} ${WRKSRC}/www-site/tag_imgs/a_project.png ${DOCSDIR}/tag_imgs
	${INSTALL_DATA} ${WRKSRC}/www-site/tag_imgs/advice_tags.png ${DOCSDIR}/tag_imgs
	${INSTALL_DATA} ${WRKSRC}/www-site/tag_imgs/class_child1.png ${DOCSDIR}/tag_imgs
	${INSTALL_DATA} ${WRKSRC}/www-site/tag_imgs/class_list.png ${DOCSDIR}/tag_imgs
	${INSTALL_DATA} ${WRKSRC}/www-site/tag_imgs/generate_tags.png ${DOCSDIR}/tag_imgs
	${INSTALL_DATA} ${WRKSRC}/www-site/tag_imgs/jump_symbol.png ${DOCSDIR}/tag_imgs
	${INSTALL_DATA} ${WRKSRC}/www-site/tag_imgs/project_name.png ${DOCSDIR}/tag_imgs
	${INSTALL_DATA} ${WRKSRC}/www-site/tag_imgs/project_open.png ${DOCSDIR}/tag_imgs
	${INSTALL_DATA} ${WRKSRC}/www-site/tag_imgs/sorted.png ${DOCSDIR}/tag_imgs
	${INSTALL_DATA} ${WRKSRC}/www-site/tag_imgs/symbols_example.png ${DOCSDIR}/tag_imgs
	${INSTALL_DATA} ${WRKSRC}/www-site/tag_imgs/tag_options.png ${DOCSDIR}/tag_imgs
	${INSTALL_DATA} ${WRKSRC}/www-site/tag_imgs/tag_options_d.png ${DOCSDIR}/tag_imgs
	${INSTALL_DATA} ${WRKSRC}/www-site/tag_imgs/this_and_parents.png ${DOCSDIR}/tag_imgs
	${INSTALL_DATA} ${WRKSRC}/www-site/tag_imgs/this_class.png ${DOCSDIR}/tag_imgs
	${INSTALL_DATA} ${WRKSRC}/www-site/tag_imgs/w_completion.png ${DOCSDIR}/tag_imgs
	${INSTALL_DATA} ${WRKSRC}/copyrigh ${DOCSDIR}/copyright
	${INSTALL_DATA} ${WRKSRC}/copying.dj ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/copying.gpl ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/copying.lgp ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/copying.rh ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/www-site/tags.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/www-site/my_file1.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/www-site/my_file2.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/www-site/my_file3.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/www-site/examples.css ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/readme.1st ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/distrib/linux.faq ${DOCSDIR}/faq.txt
	${INSTALL_DATA} ${WRKSRC}/doc/setedit.txt.gz ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/sdg.txt.gz ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/infview.txt.gz ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/setedit.info ${PREFIX}/info
	${INSTALL_DATA} ${WRKSRC}/doc/sdg.info ${PREFIX}/info
	${INSTALL_DATA} ${WRKSRC}/doc/infview.info ${PREFIX}/info
.endif

.include <bsd.port.post.mk>
