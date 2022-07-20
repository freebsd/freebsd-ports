PORTNAME=	libmpcbdm
PORTVERSION=	0.0.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/libmpc8xx/libmpc8xx/${PORTVERSION} \
		http://mbsd.msk.ru/dist/
DISTNAME=	mpc8xx-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Standalone library to control various mpc8xx boards

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	amd64 i386

USES=		gmake libtool
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/libmpc8xx

post-patch:
	@${REINPLACE_CMD} -e \
		's| $$(includedir)| $$(DESTDIR)$$(includedir)|' \
		${WRKSRC}/libmpc8xx/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} Flash.dev ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
