# New ports collection makefile for:    kaffe
# Version required:     0.8.0
# Date created:         10 February 1997
# Whom:                 Mark Huizer <xaa@stack.nl>
#
# $Id: Makefile,v 1.17 1997/02/18 11:36:08 obrien Exp $
#

DISTNAME=	kaffe-0.8.0
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.sarc.city.ac.uk/pub/kaffe/
EXTRACT_SUFX=	.tgz

MAINTAINER=	xaa@stack.nl

RUN_DEPENDS=	${PREFIX}/share/java/classes.zip:${PORTSDIR}/lang/jdk

GNU_CONFIGURE=	yes
MAN1=		kaffe.1

do-configure:
		@(cd ${WRKSRC}; ${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS})

pre-install:
	@( if test "`${MD5} ${PREFIX}/share/java/classes.zip | ${AWK} '{print $$4}'`" != "`cat ${FILESDIR}/classes.zip.1.02.md5`" ; then \
	echo "kaffe REQUIRES the classes.zip file from ports/lang/jdk, version 1.02"; \
	exit 1 ; \
	fi)

post-install:
	${MKDIR} ${PREFIX}/share/kaffe
	${INSTALL_DATA} ${WRKSRC}/license.terms ${PREFIX}/share/kaffe
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
