# $FreeBSD$

PORTNAME=	postgresql_autodoc
PORTVERSION=	1.41
CATEGORIES=	databases
MASTER_SITES=	http://www.rbt.ca/autodoc/binaries/
DIST_SUBDIR=	postgresql

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Automatic documentation generator for postgresql databases

BUILD_DEPENDS=	p5-HTML-Template>=0:${PORTSDIR}/www/p5-HTML-Template \
		p5-Term-ReadKey>=0:${PORTSDIR}/devel/p5-Term-ReadKey \
		p5-DBD-Pg>=0:${PORTSDIR}/databases/p5-DBD-Pg

USE_GMAKE=	yes
USE_PERL5=	yes
CONFIGURE_ARGS+=--datadir=${DATADIR}

MAN1=		postgresql_autodoc.1

WRKSRC=		${WRKDIR}/postgresql_autodoc

do-install:
		@${INSTALL_SCRIPT} ${WRKSRC}/postgresql_autodoc ${PREFIX}/bin
		@${INSTALL_MAN} ${WRKSRC}/postgresql_autodoc.1 ${MANPREFIX}/man/man1
		@${MKDIR} ${DATADIR}
		@${INSTALL_DATA} ${WRKSRC}/*.tmpl ${DATADIR}

.include <bsd.port.mk>
