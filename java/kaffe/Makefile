# New ports collection makefile for:    kaffe
# Version required:     0.5p4
# Date created:         18 September 1996
# Whom:                 Mark Huizer <xaa@stack.urc.tue.nl>
#
# $Id: Makefile,v 1.9 1996/09/23 23:44:25 chuckr Exp $
#

DISTNAME=	kaffe-0.5.5
PKGNAME=	kaffe-0.5.5
CATEGORIES+=	www
MASTER_SITES=	ftp://ftp.sarc.city.ac.uk/pub/kaffe/
MASTER_SITES+=	ftp://alterego.stack.urc.tue.nl/pub/kaffe/
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
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/kaffe.1
.endif
	test -d ${PREFIX}/share/kaffe || mkdir -p ${PREFIX}/share/kaffe
	install -c -m 644  ${WRKSRC}/license.terms ${PREFIX}/share/kaffe
	/sbin/ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>
