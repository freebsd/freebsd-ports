# Created by: shurd@FreeBSD.org
# $FreeBSD$

PORTNAME=	xnec2c
PORTVERSION=	3.1
CATEGORIES=	comms hamradio
MASTER_SITES=	http://www.qsl.net/5b4az/pkg/nec2/xnec2c/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	shurd

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Used to calculate antenna patterns useful to ham radio

LICENSE=	GPLv2

LIB_DEPENDS=	libccm.so:${PORTSDIR}/math/ccmath

GNU_CONFIGURE=	yes
USES=		tar:bzip2 pkgconfig gmake
USE_GNOME=	gtk20

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

.include <bsd.port.pre.mk>

post-extract:
	${CP} ${PATCHDIR}/clog.c ${WRKSRC}/src
.if	${OSVERSION} < 900000
	${CP} ${PATCHDIR}/cexp.[ch] ${WRKSRC}/src
.else
	${TOUCH} ${WRKSRC}/src/cexp.c
	${TOUCH} ${WRKSRC}/src/cexp.h
.endif

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/xnec2c.html ${STAGEDIR}${DOCSDIR}/xnec2c.html
	${MKDIR} ${STAGEDIR}${DOCSDIR}/images
	${INSTALL_DATA} ${WRKSRC}/doc/images/charges.png ${STAGEDIR}${DOCSDIR}/images/charges.png
	${INSTALL_DATA} ${WRKSRC}/doc/images/currents.png ${STAGEDIR}${DOCSDIR}/images/currents.png
	${INSTALL_DATA} ${WRKSRC}/doc/images/excitation.png ${STAGEDIR}${DOCSDIR}/images/excitation.png
	${INSTALL_DATA} ${WRKSRC}/doc/images/freq_plots.png ${STAGEDIR}${DOCSDIR}/images/freq_plots.png
	${INSTALL_DATA} ${WRKSRC}/doc/images/nec2_edit.png ${STAGEDIR}${DOCSDIR}/images/nec2_edit.png
	${INSTALL_DATA} ${WRKSRC}/doc/images/radiation.png ${STAGEDIR}${DOCSDIR}/images/radiation.png
	${INSTALL_DATA} ${WRKSRC}/doc/images/wire.png ${STAGEDIR}${DOCSDIR}/images/wire.png

.include <bsd.port.post.mk>
