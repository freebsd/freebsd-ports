# New ports collection makefile for:	mpg123
# Version required:		0.59r
# Date created:			25 June 1997
# Whom:				Carey Jones <mcj@acquiesce.org>
#
# $FreeBSD$
#

DISTNAME=	mpg123-0.59r
CATEGORIES=	audio ipv6
MASTER_SITES=	http://www.mpg123.de/mpg123/ \
		http://www-ti.informatik.uni-tuebingen.de/~hippm/mpg123/ \
		ftp://ftp.tu-clausthal.de/pub/unix/audio/mpg123/ \
		http://ftp.tu-clausthal.de/pub/unix/audio/mpg123/

PATCH_SITES=	ftp://ftp.kame.net/pub/kame/misc/
PATCHFILES=	mpg123-059r-v6-20000217.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	jkoshy@freebsd.org

.if defined(OPT_ESOUND)
LIB_DEPENDS=	esd.2:${PORTSDIR}/audio/esound
.endif

ONLY_FOR_ARCHS=	i386

MAN1=		mpg123.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 400014
MAKE_ENV+=	USE_INET6=yes
.endif

.if defined(OPT_ESOUND)
ALL_TARGET=	freebsd-esd
.else
ALL_TARGET=	freebsd
.endif

pre-configure:
.if !defined(OPT_ESOUND) && exists(${PREFIX}/lib/libesd.a)
	@${ECHO_MSG} "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
	@${ECHO_MSG} "Note: you can set OPT_ESOUND to \"yes\" to compile mpg123 with esd support."
	@${ECHO_MSG} "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
.endif
.if $(MACHINE_ARCH) == "i386"
.if !defined(OPT_ARCH) || (($(OPT_ARCH) != "i486") && ($(OPT_ARCH) != "i586") \
    && ($(OPT_ARCH) != "3dnow"))
	@${ECHO_MSG} "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
	@${ECHO_MSG} "Note: you can set OPT_ARCH to optimize for your hardware. (Eg:- make OPT_ARCH=i486)"
.if $(PORTOBJFORMAT) == "elf"
	@${ECHO_MSG} "Valid values are: i486, i586, 3dnow"
.else
	@${ECHO_MSG} "Valid values are: i486"
.endif
	@${ECHO_MSG} "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
.endif
.endif

.if $(PORTOBJFORMAT) == "elf"
OPT_ARCH?=	i586
.else
OPT_ARCH?=	i486
.endif

# Uncomment this line below to optimise for i486 family CPUs on ELF boxes
# OPT_ARCH=	i486

.if defined(OPT_ARCH)
MAKE_ARGS+=	OPT_ARCH=$(OPT_ARCH)
.endif

.if defined(OPT_ESOUND)
MAKE_ARGS+=	OPT_ESOUND=$(OPT_ESOUND)
.endif

.include <bsd.port.post.mk>
