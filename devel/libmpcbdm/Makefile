# New ports collection makefile for:	libmpcbdm
# Date created:		2006-06-24
# Whom:			Stanislav Sedov <stas@fonon.realnet>
#
# $FreeBSD$
#

PORTNAME=	libmpcbdm
PORTVERSION=	0.0.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://mbsd.msk.ru/dist/
MASTER_SITE_SUBDIR=	libmpc8xx
DISTNAME=	mpc8xx-${PORTVERSION}

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Standalone library to control various mpc8xx boards

WRKSRC=		${WRKDIR}/libmpc8xx
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

ONLY_FOR_ARCHS=	i386

post-patch:
	@${REINPLACE_CMD} -E -e 's,(objformat=).*,\1elf,' \
		${WRKSRC}/configure

post-install:
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/Flash.dev ${DATADIR}

.include <bsd.port.mk>
