# New ports collection makefile for:    kaffe
# Version required:     0.8.3
# Date created:         21 March 1997
# Whom:                 Mark Huizer <xaa@stack.nl>
#
# $Id: Makefile,v 1.20 1997/03/11 12:03:14 asami Exp $
#

DISTNAME=	kaffe-0.8.3
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.kaffe.org/pub/kaffe/
EXTRACT_SUFX=	.tgz
DISTFILES=	${DISTNAME}.tgz kaffe-0.8.3-package-biss-net.com.tgz

MAINTAINER=	xaa@stack.nl

RUN_DEPENDS=	${PREFIX}/share/java/classes.zip:${PORTSDIR}/lang/jdk

GNU_CONFIGURE=	yes
MAN1=		kaffe.1

#do-configure:
#		@(cd ${WRKSRC}; ${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS})

pre-install:
	@( if test "`${MD5} ${PREFIX}/share/java/classes.zip | ${AWK} '{print $$4}'`" != "`cat ${FILESDIR}/classes.zip.1.02.md5`" ; then \
	echo "kaffe REQUIRES the classes.zip file from ports/lang/jdk, version 1.02"; \
	exit 1 ; \
	fi)

post-install:
	${MKDIR} ${PREFIX}/share/kaffe
	${INSTALL_DATA} ${WRKSRC}/ENVIRONMENT ${WRKSRC}/license.terms ${PREFIX}/share/kaffe
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
