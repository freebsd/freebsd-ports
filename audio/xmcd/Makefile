# New ports collection makefile for:	xmcd
# Date created:		16 Februar 1995
# Whom:			Gennady Sorokopud <gena@NetVision.net.il>
#
# $FreeBSD$
#

PORTNAME=	xmcd
PORTVERSION=	3.1
CATEGORIES=	audio
MASTER_SITES=	http://www.ibiblio.org/tkan/download/xmcd/3.1.1/src/
DISTNAME=	xmcd-3.1.1

MAINTAINER=	eischen@vigrid.com

USE_MOTIF=	yes
USE_IMAKE=	yes
WRKSRC=		${WRKDIR}/xmcd-3.1
PLIST_SUB+=	RELEASE=${OSREL:R} ARCH=${ARCH}

MAN1=		cda.1 xmcd.1
MANCOMPRESSED=	no
RMAN=		${X11BASE}/bin/rman

.include <bsd.port.pre.mk>

post-extract:
	@${CHMOD} -R u+w ${WRKSRC}

pre-patch:
	@${CP} ${WRKSRC}/xmcd_d/XMcd.ad ${WRKSRC}/xmcd_d/XMcd.ad.in

post-patch:
	@${SED} -e "s;@PREFIX@;${PREFIX};g" ${WRKSRC}/xmcd_d/XMcd.ad.in \
		> ${WRKSRC}/xmcd_d/XMcd.ad

.if ${XFREE86_VERSION} == 4
post-build:
	(cd ${WRKSRC}; \
	 for i in xmcd cda; do \
		${RM} -f $${i}-1.html; \
		${RMAN} -f HTML < $${i}_d/$${i}.man > $${i}-1.html && \
			${MV} $${i}-1.html $${i}.1.html; \
	 done)
.endif

post-install:
	@${CAT} ${PKGMESSAGE}
	@${CP} ${WRKSRC}/xmcd_d/XMcd.ad ${PREFIX}/lib/X11/app-defaults/XMcd
.if ${XFREE86_VERSION} == 4
	(cd ${WRKSRC}; \
	 for i in xmcd cda; do \
		${INSTALL_MAN} $${i}.1.html ${PREFIX}/lib/X11/doc/html; \
	 done)
.endif

.include <bsd.port.post.mk>
