# New ports collection makefile for:	elk
# Date created:		08 March 1995
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	elk
PORTVERSION=	3.99.6
PORTREVISION=	1
CATEGORIES=	lang scheme
MASTER_SITES=	http://sam.zoy.org/projects/elk/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An embeddable Scheme interpreter

LIB_DEPENDS=	gdbm.3:${PORTSDIR}/databases/gdbm \
		elf.0:${PORTSDIR}/devel/libelf

USE_BZIP2=	yes
USE_MOTIF=	yes
USE_LIBTOOL=	yes
LIBTOOLFLAGS=	# none
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
INSTALLS_SHLIB=	yes

MAN1=		elk.1

CPPFLAGS=	-I${LOCALBASE}/include/libelf -I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/man/elk.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	@${TAR} -C ${WRKSRC}/examples --exclude "*Makefile*" -cf - . | \
		${TAR} -C ${EXAMPLESDIR} --unlink -xf -
	@${CHOWN} -R ${SHAREMODE}:${SHAREGRP} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
