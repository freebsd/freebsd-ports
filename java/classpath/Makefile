# ex:ts=8
# Ports collection makefile for:	classpath
# Date created:			Sep 1, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	classpath
PORTVERSION=	0.14
CATEGORIES=	java
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GNU project to create a free Java class library

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip

USE_GNOME=	gtk20 libartlgpl2 pkgconfig
USE_JAVA=	yes
USE_JIKES=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-jni --with-jikes
USE_GMAKE=	yes

INFO=		hacking vmintegration
PLIST_FILES=	lib/security/classpath.security

.include <bsd.port.pre.mk>

post-install:
.for dir in ${PREFIX}/share/classpath ${PREFIX}/lib/classpath
	@${FIND} ${dir} ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${dir} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.endfor
	@${ECHO_CMD} '@unexec rmdir %D/lib/security 2>/dev/null || true' >> ${TMPPLIST}

.include <bsd.port.post.mk>
