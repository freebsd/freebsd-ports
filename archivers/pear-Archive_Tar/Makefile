# Ports collection makefile for:  pear-Archive_Tar
# Date created:			  28 November 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	Archive_Tar
PORTVERSION=	1.1
CATEGORIES=	archivers www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR tar file management class

BUILD_DEPENDS=	pear:${PORTSDIR}/lang/php4
RUN_DEPENDS=	${BUILD_DEPENDS}

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../devel/pear-PEAR/Makefile.common"

do-install:
	@${MKDIR} ${PEARDIR}/Archive
	@${CP} -Rp ${WRKSRC}/Archive ${PEARDIR}
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PEARDIR}/Archive
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs/Archive_Tar.txt ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.post.mk>
