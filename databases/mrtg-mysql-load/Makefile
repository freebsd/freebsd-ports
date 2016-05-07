# Created by: Piet Delport <pjd@303.za.net>
# $FreeBSD$

PORTNAME=	mrtg-mysql-load
PORTVERSION=	1.02
PORTREVISION=	4
CATEGORIES=	databases net-mgmt
MASTER_SITES=	http://www.bitbybit.dk/mysql/mrtg-mysql-load/ \
		http://freebsd.unixfreunde.de/sources/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MySQL load analysis fetcher for MRTG

RUN_DEPENDS=	mrtg:net-mgmt/mrtg

USES=		perl5
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_PERL5=	run
USE_MYSQL=	yes

PLIST_FILES=	bin/mrtg-mysql-load etc/mrtg/mrtg.cfg-mysql-load.example \
		etc/mrtg/mysql-load-cfg.example man/man1/${PORTNAME}.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|%%PERL%%|${PERL}|' ${WRKSRC}/${PORTNAME}

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/mrtg
	@${INSTALL_DATA} ${WRKSRC}/mrtg-cfg.example  ${STAGEDIR}${PREFIX}/etc/mrtg/mrtg.cfg-mysql-load.example
	@${INSTALL_DATA} ${WRKSRC}/mysql-load-cfg.example  ${STAGEDIR}${PREFIX}/etc/mrtg/mysql-load-cfg.example
	@${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
