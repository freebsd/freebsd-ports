# $FreeBSD$

PORTNAME=	postgresql_autodoc
PORTVERSION=	1.41
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://www.rbt.ca/autodoc/binaries/
DIST_SUBDIR=	postgresql

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Automatic documentation generator for postgresql databases

RUN_DEPENDS=	p5-HTML-Template>=0:${PORTSDIR}/www/p5-HTML-Template \
		p5-Term-ReadKey>=0:${PORTSDIR}/devel/p5-Term-ReadKey \
		p5-DBD-Pg>=0:${PORTSDIR}/databases/p5-DBD-Pg

USES+=		gmake perl5 shebangfix
SHEBANG_FILES=	postgresql_autodoc.pl
CONFIGURE_ARGS+=--datadir=${DATADIR}

WRKSRC=		${WRKDIR}/postgresql_autodoc

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/postgresql_autodoc ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/postgresql_autodoc.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.tmpl ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
