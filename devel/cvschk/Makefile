PORTNAME=	cvschk
PORTVERSION=	1.12
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	LOCAL/mandree/ \
		# http://cvs.sslug.dk/cvs2html/utils/
DISTNAME=	cvschk
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Quick offline checker for CVS modifications
WWW=		http://web.archive.org/web/20121006163548/http://cvs.sslug.dk/cvs2html/

LICENSE=	GPLv1

USES=		perl5
USE_PERL5=	run
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/cvschk share/man/man1/cvschk.1.gz

do-configure:
	${SED} -e "s,^#!/usr/bin/perl -w,#! ${PERL} -w," \
	<${DISTDIR}/${DISTNAME} >${WRKSRC}/${DISTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN}	  ${FILESDIR}/cvschk.1  ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
