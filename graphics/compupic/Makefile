# New ports collection makefile for:    compupic
# Date created:         Thu Mar 14 22:40:58 PST 2002
# Whom:                 Abel Chow <ozsanh45vds001@sneakemail.com>
#
# $FreeBSD$
#

PORTNAME=	compupic
PORTVERSION=	5.1.1063
CATEGORIES=	graphics
MASTER_SITES=	http://files.photodex.com/archive/unix/
DISTNAME=	${PORTNAME}-${PORTVERSION}-i386-freebsd
EXTRACT_ONLY=	# extracted directly in install target

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Digital content manager

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
ONLY_FOR_ARCHS=	i386

MAN1=		compupic.1

do-install:
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${DISTNAME}.tar.gz \
		${EXTRACT_AFTER_ARGS} -C ${PREFIX}
	${RM} -f ${PREFIX}/bin/compupic
	${LN} -sf ${PREFIX}/compupic/compupic ${PREFIX}/bin/compupic
	${INSTALL_MAN} ${PREFIX}/compupic/compupic.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
