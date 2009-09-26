# New ports collection makefile for:	qemacs
# Date created:				27 January 2003
# Whom:			Brad Davis <so14k@so14k.com> et al
#
# $FreeBSD$
#

PORTNAME=	qemacs
PORTVERSION=	0.3.1
PORTREVISION=	3
CATEGORIES=	editors
MASTER_SITES=	http://fabrice.bellard.free.fr/qemacs/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quick Emacs - a very small but powerful UNIX editor

USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix="${PREFIX}" --make="${GMAKE}" --cc="${CC}" \
		--extra-cflags="${CFLAGS}" --extra-ldflags="${LDFLAGS}"
USE_GCC=	3.4

DEPRECATED=	depends on old version of GCC, no maintainer, not used by any other port, dead upstream
EXPIRATION_DATE=2009-10-26

DATADIR=	${PREFIX}/share/qe

MAN1=		qe.1
MLINKS=		qe.1 qemacs.1
PORTDOCS=	qe-doc.html
PLIST_FILES=	bin/html2png bin/qe bin/qemacs \
		%%DATADIR%%/kmaps %%DATADIR%%/ligatures
PLIST_DIRS=	%%DATADIR%%

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
IGNORE=		crashes on startup
.endif

.if defined(WITHOUT_PNG)
CONFIGURE_ARGS+=	--disable-png
.else
LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png
CFLAGS+=	`libpng-config --I_opts`
LDFLAGS=	`libpng-config --L_opts`
.endif

.if defined(WITHOUT_X11)
PKGNAMESUFFIX=	-nox11
CONFIGURE_ARGS+=	--disable-x11
.else
USE_XORG=	x11 xv xext
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-Wall -g|-Wall|g ; \
		 s|-m.*386||g ; \
		 s|-ldl||g ; \
		 s|-L/usr/X11R6/lib||g ; \
		 s|make -C|$$(MAKE) -C|g ; \
		 s|HOST_CC|CC|g'
	@${REINPLACE_CMD} -e 's|/usr/share/doc/qemacs/|${DOCSDIR}/|g ; \
		 s|README.gz|qe-doc.html|g' ${WRKSRC}/qe.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/html2png ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/qe ${PREFIX}/bin
	${LN} -sf qe ${PREFIX}/bin/qemacs
	${INSTALL_MAN} ${WRKSRC}/qe.1 ${MANPREFIX}/man/man1
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/kmaps ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/ligatures ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/qe-doc.html ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
