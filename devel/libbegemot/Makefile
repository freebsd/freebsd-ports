# Created by: Andrey V. Elsukov <bu7cher@yandex.ru>
# $FreeBSD$

PORTNAME=	libbegemot
PORTVERSION=	1.11
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	http://people.freebsd.org/~harti/libbegemot/ \
		http://m1cro.me/ports/distfiles/libbegemot/

MAINTAINER=	rum1cro@yandex.ru
COMMENT=	Function library for begemot tools

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

GNU_CONFIGURE=	yes
USES=		gmake libtool
USE_AUTOTOOLS=	automake:env autoconf:env libltdl libtoolize
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

MAN_FILES=	cstrc.1 frame.1 getfields.1 intro.1 panic.1 prstat.1 readline.1 \
		rpoll.1 strnchr.1 strnlen.1 strsave.1 strtrimsp.1 verb.1 xalloc.1

run-autotools::
	@(cd ${CONFIGURE_WRKSRC} && ${ACLOCAL} -I ${LIBTOOL_SHAREDIR}/libltdl/)
	@(cd ${CONFIGURE_WRKSRC} && ${AUTOCONF})
	@${REINPLACE_CMD} -e "/^ltmain=/!s^\$$ac_aux_dir/ltmain.sh^${LIBTOOLFLAGS} ${LTMAIN}^g" \
		-e '/^LIBTOOL=/s^\$$(top_builddir)/libtool^${LIBTOOL}^g' \
			${WRKSRC}/configure

pre-install:
	@${STRIP_CMD} ${WRKSRC}/.libs/libbegemot.so

post-install:
.for i in ${MAN_FILES}
	@${CP} ${WRKSRC}/${i:S/.1/.man/} ${WRKSRC}/${i}
	${INSTALL_MAN} ${WRKSRC}/${i} ${STAGEDIR}${MANPREFIX}/man/man1
.endfor

.include <bsd.port.mk>
