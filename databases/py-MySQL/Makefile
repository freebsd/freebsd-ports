# New ports collection makefile for:	py-MySQL
# Date created:				05 September 1999
# Whom:                 		Dominik Rothert <dr@domix.de>
#
# $FreeBSD$
#

PORTNAME=	py-MySQL
PORTVERSION=	1.4
CATEGORIES=	databases python
MASTER_SITES=	http://web.tryc.on.ca/mysql/Downloads/Contrib/ \
		http://mysql.orst.edu/Downloads/Contrib/ \
		http://mysql.netvisao.pt/Downloads/Contrib/
DISTNAME=	MySQLmodule-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Access a MySQL database through Python

LIB_DEPENDS=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client

PLIST_FILES=	lib/%%PYTHON_VERSION%%/site-packages/MySQLmodule.so
USE_PYTHON=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 210
ALL_TARGET=	MySQLmodule.so
.endif
.if ${PYTHON_REL} >= 220
MAKEFILE_PREIN=	${FILESDIR}/Makefile.pre.in
.else
MAKEFILE_PREIN=	${PYTHONPREFIX_LIBDIR}/config/Makefile.pre.in
.endif

pre-configure:
	${CP} ${FILESDIR}/Setup ${WRKSRC}/Setup
.if ${PYTHON_REL} >= 230
	${SED} -e 's,@DEFS@,,g' ${MAKEFILE_PREIN} > ${WRKSRC}/Makefile.pre.in
.else
	${LN} -s ${MAKEFILE_PREIN} ${WRKSRC}/
.endif

do-configure:
	cd ${WRKSRC} && ${MAKE} -f Makefile.pre.in boot

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${PREFIX}/share/doc/py-MySQL
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/py-MySQL
	@${ECHO_CMD} "share/doc/py-MySQL/README" >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm share/doc/py-MySQL" >> ${TMPPLIST}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
