# Created by: ijliao
# $FreeBSD$

PORTNAME=	trio
PORTVERSION=	1.16
CATEGORIES=	devel
MASTER_SITES=	SF/c${PORTNAME}/${PORTNAME}

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Fully matured and stable set of printf and string functions

LICENSE=	BSD2CLAUSE

BROKEN_mips=		fails to link: /usr/bin/ld: No such file: No such file or directory
BROKEN_mips64=		fails to link: /usr/bin/ld: No such file: No such file or directory
BROKEN_powerpc64=	fails to link: /usr/bin/ld: No such file: No such file or directory

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${FIND} doc | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
