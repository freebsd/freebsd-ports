# New ports collection makefile for: wily
# Date created:   	23 September 1997
# Whom: 		koshy
#
# $FreeBSD$
#

PORTNAME=	wily
PORTVERSION=	0.13.42
PORTREVISION=	2
CATEGORIES=	editors plan9
MASTER_SITES=	SF/${PORTNAME}/baseline/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A clone of the Plan9 editor `acme'

RUN_DEPENDS=	${LOCALBASE}/bin/rc:${PORTSDIR}/shells/rc \
		${LOCALBASE}/lib/X11/fonts/Xg/unicode.9.font:${PORTSDIR}/x11-fonts/Xg

USE_XORG=	x11 ice xt
GNU_CONFIGURE=	YES
USE_GMAKE=	YES
MAN1=		wgoto.1 win.1 wreplace.1 Tag.1 mktags.1 Man.1
MAKE_JOBS_UNSAFE=	yes

PORTDOCS=	index.html intro.html download.html credits.html FAQ.html \
		onepage.html user.html idioms.html C.html python.html \
		hack.html AcmeVsWily.html Tcl.html \
		pythonpaper.html winmanager.html auug.html one.html \
		example.gif thumb.gif cartoon.gif \
		FAQ.txt Tcl.txt changes.txt perl.txt \
		Credits fonts mouse
TUTEDOCS=	hello.c start typescript
TUTESHS=	findword script send_to_gary

post-patch:
	cd  ${WRKSRC}/tools/win; ${REINPLACE_CMD} -e 's," in " __FUNCTION__ "()",,' \
		win.c wgoto.c wreplace.c; \
		${CHMOD} 755 configure mkinstalldirs;

# Run the configure script in the tools directory.
post-configure:
	@${RM} ${WRKSRC}/tools/win/config.cache
	cd ${WRKSRC}/tools/win && \
		${SETENV} CC=${CC} "CFLAGS=${CFLAGS}" \
		${SH} ./configure --prefix=${PREFIX}

# The default Wily makefile does not install any documentation.  Rectify.
post-install:
	@${STRIP_CMD} ${PREFIX}/bin/wily
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/tute
. for doc in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/Doc/${doc} ${DOCSDIR}
. endfor
. for doc in ${TUTEDOCS}
	@${INSTALL_DATA} ${WRKSRC}/Doc/tute/${doc} ${DOCSDIR}/tute
. endfor
. for doc in ${TUTESHS}
	@${INSTALL_SCRIPT} ${WRKSRC}/Doc/tute/${doc} ${DOCSDIR}/tute
. endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
