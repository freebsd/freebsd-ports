# Created by: will
# $FreeBSD$

PORTNAME=	cvs2html
PORTVERSION=	1.98
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	http://www.bayofrum.net/dist/${PORTNAME}/${PORTVERSION}/ \
		http://cvs.sslug.dk/cvs2html/utils/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Perl script to turn ``cvs log'' output into HTML

LICENSE=	GPLv2

PLIST_FILES=	bin/cvs2html
USES=		perl5
NO_BUILD=	yes

do-extract:
	@${MKDIR} ${WRKDIR}
	@${CP} ${DISTDIR}/${PORTNAME} ${WRKDIR}

post-patch:
	${REINPLACE_CMD} -e '1s|\(#!\).*$$|\1${PERL}|' ${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
