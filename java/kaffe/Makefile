# New ports collection makefile for:    kaffe
# Version required:     0.4
# Date created:         20 February 1995
# Whom:                 Tim Wilkinson <tim@sarc.city.ac.uk>
#
# $Id: Makefile,v 1.3 1996/07/04 01:23:21 gpalmer Exp $
#

DISTNAME=	kaffe-0.4p2
CATEGORIES+=	www
MASTER_SITES=	ftp://ftp.sarc.city.ac.uk/pub/kaffe/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tim@sarc.city.ac.uk

RUN_DEPENDS=	${PREFIX}/share/java/classes.zip:${PORTSDIR}/www/jdk

GNU_CONFIGURE=	yes

do-configure:
		@(cd ${WRKSRC}; ${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS})

pre-install:
	@( if test "`${MD5} ${PREFIX}/share/java/classes.zip | ${AWK} '{print $$4}'`" != "`cat ${FILESDIR}/classes.zip.1.02.md5`" ; then \
	echo "kaffe REQUIRES the classes.zip file from ports/www/jdk, version 1.02"; \
	exit 1 ; \
	fi)

post-install:
	test -d ${PREFIX}/share/kaffe || mkdir -p ${PREFIX}/share/kaffe
	install -c -m 644  ${WRKSRC}/license.terms ${PREFIX}/share/kaffe
	/sbin/ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>
