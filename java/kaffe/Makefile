# New ports collection makefile for:    kaffe
# Version required:     0.5p3
# Date created:         08 August 1996
# Whom:                 Mark Huizer <xaa@stack.urc.tue.nl>
#
# $Id$
#

DISTNAME=	kaffe-0.5p3
PKGNAME=	kaffe-0.5.3
CATEGORIES+=	www
MASTER_SITES=	ftp://ftp.sarc.city.ac.uk/pub/kaffe/
EXTRACT_SUFX=	.tgz

MAINTAINER=	xaa@stack.urc.tue.nl

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
