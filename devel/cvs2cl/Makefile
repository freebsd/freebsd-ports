# New ports collection makefile for:	cvs2cl
# Date created:		6 June 2000
# Whom:			knu@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	cvs2cl
PORTVERSION=	2.59
CATEGORIES=	devel
MASTER_SITES=	http://www.red-bean.com/cvs2cl/
DISTFILES=	${PORTNAME}.pl
EXTRACT_ONLY=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CVS-log-message-to-ChangeLog conversion script

USE_PERL5=	yes

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
MANCOMPRESSED=	no
MAN1=		${PORTNAME}.1
PLIST_FILES=	bin/${PORTNAME}

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} ${WRKSRC}/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e "s|exec perl -w -x|exec ${PERL} -w -x|" \
		-e "s|#!perl -w|#!${PERL} -w|" ${WRKSRC}/${PORTNAME}

do-install:
	@pod2man ${WRKSRC}/${PORTNAME} > ${WRKSRC}/${PORTNAME}.1
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1/

.include <bsd.port.mk>
