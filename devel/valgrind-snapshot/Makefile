# Ports collection makefile for:	valgrind
# Date created:				April 19 2004
# Whom:					Simon Barner <barner@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	valgrind
PORTVERSION=	352
CATEGORIES=	devel
MASTER_SITES=	http://www.rabson.org/
PKGNAMESUFFIX=	-snapshot
DISTNAME=	${PORTNAME}-current-${PORTVERSION}

MAINTAINER=	barner@gmx.de
COMMENT=	A (memory) debugging and profiling tool

CONFLICTS=	valgrind-[0-9]*
LATEST_LINK=	valgrind-snapshot

ONLY_FOR_ARCHS=	i386

USE_GMAKE=	yes
USE_PERL5_BUILD=yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

WRKSRC=		${WRKDIR}/${DISTNAME}

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		"can\'t be built. Your Perl version is too old. Please use lang/perl5.8 port to upgrade your Perl"
.endif

PROCFS!=	/sbin/mount | ${GREP} '^procfs' | ${AWK} '{print $1}'

pre-everything::

.if ${PROCFS}
	@${ECHO_CMD} ""
	@${ECHO_CMD} "Check if procfs is running: YES"
.else
	@${ECHO_CMD} "-----------------------------------------------------------"
	@${ECHO_CMD} ""
	@${ECHO_CMD} "Valgrind needs a running procfs, which is not"
	@${ECHO_CMD} "activated on your system. Please read the procfs\(5\)"
	@${ECHO_CMD} "manpage and add the following line to /etc/fstab:"
	@${ECHO_CMD} ""
	@${ECHO_CMD} "proc /proc procfs rw 0 0"
	@${ECHO_CMD} ""
	@${ECHO_CMD} "-----------------------------------------------------------"
.endif

pre-patch:
.ifdef(NOPORTDOCS)
	${FIND} ${WRKSRC} -name "Makefile.in" -exec \
		${REINPLACE_CMD} -e "s/docs//g" {} \;
.endif

.include <bsd.port.post.mk>
