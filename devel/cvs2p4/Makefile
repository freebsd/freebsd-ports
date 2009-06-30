# New ports collection makefile for:	cvs2p4
# Date created:		2 September 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	cvs2p4
PORTVERSION=	3.1
CATEGORIES+=	devel
MASTER_SITES=	ftp://public.perforce.com/public/perforce/utils/cvs2p4/
EXTRACT_SUFX=	.tar

MAINTAINER=	scjamorim@bsd.com.br
COMMENT=	CVS to Perforce Converter

REINPLACE_ARGS=	-i ""
NO_BUILD=	yes
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

PERFORCE_PORT?=	1666

post-patch:
	@${REINPLACE_CMD} \
		-e 's,!!PREFIX!!,${PREFIX},g;' \
		-e 's,!!PERFORCE_PORT!!,${PERFORCE_PORT},g;' \
		${WRKSRC}/test/config.test
	@${FIND} ${WRKSRC} -name '*.orig' -delete
	@${FIND} ${WRKSRC} -name '*.bak' -delete

do-install:
	${MKDIR} ${PREFIX}/${PORTNAME}
	${CP} -R ${WRKSRC}/* ${PREFIX}/${PORTNAME}/

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
