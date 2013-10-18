# Created by: Andrey V. Elsukov <bu7cher@yandex.ru>
# $FreeBSD$

PORTNAME=	libbegemot
PORTVERSION=	1.11
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://people.freebsd.org/~harti/libbegemot/
DISTNAME=	libbegemot-${PORTVERSION}

MAINTAINER=	rum1cro@yandex.ru
COMMENT=	A function library for begemot tools

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	automake:env autoconf:env libltdl libtool
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

MAN1=	cstrc.1 frame.1 getfields.1 intro.1 panic.1 prstat.1 readline.1 \
		rpoll.1 strnchr.1 strnlen.1 strsave.1 strtrimsp.1 verb.1 xalloc.1
MLINKS=	xalloc.1 xrealloc.1

NO_STAGE=	yes
run-autotools::
	@(cd ${CONFIGURE_WRKSRC} && ${ACLOCAL} -I ${LIBTOOL_SHAREDIR}/libltdl/)
	@(cd ${CONFIGURE_WRKSRC} && ${AUTOCONF})
	@${REINPLACE_CMD} -e "/^ltmain=/!s^\$$ac_aux_dir/ltmain.sh^${LIBTOOLFLAGS} ${LTMAIN}^g" \
		-e '/^LIBTOOL=/s^\$$(top_builddir)/libtool^${LIBTOOL}^g' \
			${WRKSRC}/configure

post-install:
.for i in ${MAN1}
	@${CP} ${WRKSRC}/${i:S/.1/.man/} ${WRKSRC}/${i}
	${INSTALL_MAN} ${WRKSRC}/${i} ${MANPREFIX}/man/man1
.endfor

.include <bsd.port.mk>
