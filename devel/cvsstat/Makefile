# Created by: petef
# $FreeBSD$

PORTNAME=	cvsstat
PORTVERSION=	2.24
CATEGORIES=	devel
MASTER_SITES=	http://cvs.sslug.dk/cvs2html/utils/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	# empty
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Transforms the output of 'cvs status' to a sorted ASCII table

USES=		perl5
NO_BUILD=	yes
PLIST_FILES=	bin/cvsstat

NO_STAGE=	yes
do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} -p ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|perl -S|${PERL} -S|' ${WRKSRC}/cvsstat

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cvsstat ${PREFIX}/bin

.include <bsd.port.mk>
