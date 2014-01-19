# Created by: Stanislav Sedov <stas@fonon.realnet>
# $FreeBSD$

PORTNAME=	libmpcbdm
PORTVERSION=	0.0.3
CATEGORIES=	devel
MASTER_SITES=	SF/libmpc8xx/libmpc8xx/${PORTVERSION} \
		http://mbsd.msk.ru/dist/

DISTNAME=	mpc8xx-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Standalone library to control various mpc8xx boards

WRKSRC=		${WRKDIR}/libmpc8xx

USES=		gmake
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

ONLY_FOR_ARCHS=	amd64 i386

post-patch:
	@${REINPLACE_CMD} -e \
		's| $$(includedir)| $$(DESTDIR)$$(includedir)|' \
		${WRKSRC}/libmpc8xx/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} Flash.dev ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
