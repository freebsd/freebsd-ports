# Ports collection makefile for:  pear-DB
# Date created:			  28 November 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	DB
PORTVERSION=	1.4.0
CATEGORIES=	databases www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR Database Abstraction Layer

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../devel/pear-PEAR/Makefile.common"

MANIFEST=	DB DB.php tests
DOCS=		IDEAS MAINTAINERS STATUS TESTERS

do-install:
.for FILE in ${MANIFEST}
	@${CP} -Rp ${WRKSRC}/${FILE} ${PEARDIR}
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PEARDIR}/${FILE}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/${FILE} ${DOCSDIR}
.endfor
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.post.mk>
