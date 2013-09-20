# Created by: Wes Peters <wes@softweyr.com>
# $FreeBSD$

PORTNAME=	snobol4
PORTVERSION=	1.4.1
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.ultimate.com/snobol/

MAINTAINER=	johans@FreeBSD.org
COMMENT=	A port of Macro SNOBOL4, supports full SNOBOL4 plus SPITBOL

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--snolibdir=${PREFIX}/lib/${PORTNAME}
USE_GMAKE=	yes
PLIST_SUB+=	VERSION=${PORTVERSION}

MAN1=		sdb.1 snobol4.1
MAN3=		snolib.3 snobol4dbm.3 snobol4random.3 \
		snobol4readline.3 snobol4tcl.3 snobol4time.3

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} 's:[^=]*\.tmp$$:${WRKSRC}/&:' ${WRKSRC}/configure

.include <bsd.port.mk>
