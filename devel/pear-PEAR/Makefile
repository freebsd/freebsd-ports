# Ports collection makefile for:  pear-PEAR
# Date created:			  22 October 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	PEAR
PORTVERSION=	1.2.1
CATEGORIES=	devel www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR Base System

BUILD_DEPENDS=	${PEARDIR}/Archive/Tar.php:${PORTSDIR}/archivers/pear-Archive_Tar	\
		${PEARDIR}/Console/Getopt.php:${PORTSDIR}/devel/pear-Console_Getopt
RUN_DEPENDS=	${BUILD_DEPENDS}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"

MANIFEST=	OS PEAR PEAR.php System.php package.dtd scripts template.spec

do-install:
	@${CP} -Rp ${WRKSRC}/* ${PEARDIR}
.for FILE in ${MANIFEST}
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PEARDIR}/${FILE}
.endfor

.include <bsd.port.post.mk>
