# New ports collection makefile for:	mpg123
# Date created:			25 June 1997
# Whom:				Carey Jones <mcj@acquiesce.org>
#
# $FreeBSD$
#

PORTNAME=	mpg123
PORTVERSION=	0.59r
PORTREVISION=	4
CATEGORIES=	audio ipv6
MASTER_SITES=	http://www.mpg123.de/mpg123/ \
		http://www-ti.informatik.uni-tuebingen.de/~hippm/mpg123/ \
		ftp://ftp.tu-clausthal.de/pub/unix/audio/mpg123/ \
		http://ftp.tu-clausthal.de/pub/unix/audio/mpg123/
DISTFILES=	mpg123-0.59r-pl1.tar.gz

PATCH_SITES=	ftp://ftp.kame.net/pub/kame/misc/ \
		http://www.unix-ag.org/Linux-Alpha/Packages/ \
		${MASTER_SITE_LOCAL:S/%SUBDIR%/sobomax/}
PATCHFILES=	mpg123-059r-v6-20000713b.diff.gz \
		mpg123-059r-recode-20010410.diff.gz \
		l3.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	sobomax@freebsd.org

WANT_ESOUND=	yes

.if defined(WITH_ICONV)
MAKE_ARGS+=	WITH_ICONV=yes
.if defined(DEFAULT_RECODE)
MAKE_ARGS+=	DEFAULT_RECODE=${DEFAULT_RECODE}
.endif
LIB_DEPENDS+=	iconv.2:${PORTSDIR}/converters/iconv
.endif

.if defined(WITH_NAS)
HAVE_NAS=	yes
LIB_DEPENDS=	audio.2:${PORTSDIR}/audio/nas
MAKE_ENV+=	HAVE_NAS=${HAVE_NAS}
.endif

MAN1=		mpg123.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 400014
MAKE_ENV+=	USE_INET6=yes
.endif

.if defined(HAVE_ESOUND)
USE_ESOUND=	yes
ALL_TARGET=	freebsd-esd
.elif defined(HAVE_NAS)
PKGNAMESUFFIX=	-nas
ALL_TARGET=	freebsd-nas
.else
ALL_TARGET=	freebsd
.endif

pre-fetch:
.if !defined(WITH_NAS)
	@${ECHO_MSG}
	@${ECHO_MSG} "If you want to compile with NAS support,"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_NAS=yes\""
	@${ECHO_MSG}
.endif
.if !defined(WITH_ICONV)
	@${ECHO_MSG}
	@${ECHO_MSG} "If you want to enable ID3 tags charset recoding,"
	@${ECHO_MSG} "hit Ctrl-C and use \"make WITH_ICONV=yes\"; you can"
	@${ECHO_MSG} "also specify DEFAULT_RECODE in 'from:to' format"
	@${ECHO_MSG}
.endif
.if ${MACHINE_ARCH} == "i386"
.if ${OSVERSION} >= 500018
.if ${MACHINE_CPU:M3dnow}
OPT_ARCH=	3dnow
.elif ${MACHINE_CPU:Mi586}
OPT_ARCH=	i586
.elif ${MACHINE_CPU:Mi486}
OPT_ARCH=	i486
.endif
.else
.if !defined(OPT_ARCH) || ((${OPT_ARCH} != "i486") && (${OPT_ARCH} != "i586") \
    && (${OPT_ARCH} != "3dnow"))
	@${ECHO_MSG} "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
	@${ECHO_MSG} "Note: you can set OPT_ARCH to optimize for your hardware."
	@${ECHO_MSG} "(e.g. make OPT_ARCH=i486)."
	@${ECHO_MSG} "Valid values are: i486, i586, 3dnow"
	@${ECHO_MSG} "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
OPT_ARCH?=	i586
.endif
.endif
.endif

.if defined(OPT_ARCH)
MAKE_ARGS+=	OPT_ARCH=${OPT_ARCH}
.endif

.include <bsd.port.post.mk>
