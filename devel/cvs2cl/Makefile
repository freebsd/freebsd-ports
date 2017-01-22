# Created by: knu@FreeBSD.org
# $FreeBSD$

PORTNAME=	cvs2cl
PORTVERSION=	2.73
CATEGORIES=	devel
MASTER_SITES=	http://www.red-bean.com/cvs2cl/ \
		http://www.sysfault.org/freebsd/${DIST_SUBDIR}/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.pl
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}
EXTRACT_ONLY=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CVS-log-message-to-ChangeLog conversion script

LICENSE=	GPLv2

USES=		perl5

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} ${WRKSRC}/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e "s|exec perl -w -x|exec ${PERL} -w -x|" \
		-e "s|#!perl -w|#!${PERL} -w|" ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@pod2man ${WRKSRC}/${PORTNAME} > ${WRKSRC}/${PORTNAME}.1
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
