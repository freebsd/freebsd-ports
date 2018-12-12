# Created by: anarcat@anarcat.ath.cx
# $FreeBSD$

PORTNAME=	ledger-smb
PORTVERSION=	1.1.12
PORTREVISION=	4
CATEGORIES=	finance perl5
MASTER_SITES=	SF/${PORTNAME}/Releases/archive-1.1/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Double entry accounting system

BUILD_DEPENDS=	p5-DBD-Pg>=0:databases/p5-DBD-Pg
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_BUILD=	yes
NO_ARCH=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
USES=		shebangfix perl5
SHEBANG_FILES=	*.pl locale/*/*.pl bin/*/*.pl utils/*/*.pl
PLIST_SUB=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"
SUB_FILES=	${PORTNAME}-httpd.conf pkg-message

post-patch:
	@${REINPLACE_CMD} -i '' -e '1s|/bin/perl|${perl_CMD}|' ${WRKSRC}/bin/lynx/gl.pl

do-install:
	@cd ${WRKDIR} ; \
		${TAR} -cf - ${PORTNAME} | ( cd ${STAGEDIR}${PREFIX} ; ${TAR} xf - )
	@cd ${STAGEDIR}${PREFIX}/${PORTNAME} ; \
		${CHMOD} 711 users templates css spool
	@${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-httpd.conf ${STAGEDIR}${PREFIX}/etc/

.include <bsd.port.mk>
