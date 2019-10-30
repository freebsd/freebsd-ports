# $FreeBSD$

PORTNAME=	erlang
PORTVERSION=	21.3
PORTREVISION=	1
CATEGORIES=	lang parallel
MASTER_SITES=	http://www.erlang.org/download/
PKGNAMESUFFIX=	-man
DISTNAME=	otp_doc_man_${PORTVERSION}
DIST_SUBDIR=	erlang

MAINTAINER=	erlang@FreeBSD.org
COMMENT=	Manual pages for Erlang/OTP

LICENSE=	APACHE20

NO_ARCH=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}

# The man-pages are put (in spite of FreeBSD's port convention) in a private
# subdir. This is to avoid cluttering up the man page name space. Also the
# Erlang man pages are more of internal documentation using the man format than
# actual system man pages. (erl.1 and epmd.1 perhaps being the exception).

do-install:
	@${ECHO_CMD} "MANPATH ${PREFIX}/lib/erlang/man" > ${WRKDIR}/erlang.conf
	${INSTALL_DATA} ${WRKDIR}/erlang.conf ${STAGEDIR}${PREFIX}/etc/man.d/erlang.conf
	for SECTION in 1 3 4 6 7; do \
		cd ${WRKSRC}/man/ && ${COPYTREE_SHARE} man$${SECTION} ${STAGEDIR}${PREFIX}/lib/erlang/man; \
	done

.include <bsd.port.mk>
