# $FreeBSD$

PORTNAME=	tio
DISTVERSIONPREFIX=	v
DISTVERSION=	1.26
CATEGORIES=	comms

MAINTAINER=	dg@syrec.org
COMMENT=	Simple TTY terminal I/O application

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf
GNU_CONFIGURE=	yes
USE_GITHUB=	yes

OPTIONS_DEFINE=	BASH
OPTIONS_DEFAULT=	BASH
OPTIONS_SUB=	yes

BASH_CONFIGURE_WITH=	bash-completion-dir

PLIST_FILES=	bin/tio \
		man/man1/tio.1.gz \
		%%BASH%%share/bash-completion/completions/tio \
		%%PORTDOCS%%%%DOCSDIR%%/README \

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
