# New ports collection makefile for:	gnats4
# Date created:				22 Aug 2003
# Whom:					Oliver Eikemeier <eikemeier@fillmore-labs.com>
#
# $FreeBSD$
#

PORTNAME=		gnats
PORTVERSION=		4.0
CATEGORIES=		databases
MASTER_SITES=		http://www.yngve.com/%SUBDIR%/ # ${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	gnats

MAINTAINER=		eikemeier@fillmore-labs.com
COMMENT=		GNATS, the GNU Problem Report Management System

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--sharedstatedir=${PREFIX}/share/gnats

LATEST_LINK=		${PKGNAMEPREFIX}gnats4${PKGNAMESUFFIX}
CONFLICTS=		gnats-3.*

USE_GMAKE=		yes
MAN1=			edit-pr.1 query-pr.1 send-pr.1
MAN5=			databases.5 dbconfig.5
MAN7=			gnats.7
MAN8=			delete-pr.8 file-pr.8 gen-index.8 gnatsd.8 mkcat.8 mkdb.8 pr-edit.8 queue-pr.8 rmcat.8
INFO=			gnats-faq gnats

PKGMESSAGE=		${WRKDIR}/pkg-message

STRIP=

BINARIES=		bin/getclose bin/query-pr libexec/gnats/gen-index libexec/gnats/gnats-pwconv \
			libexec/gnats/gnatsd libexec/gnats/pr-age libexec/gnats/pr-edit libexec/gnats/queue-pr

.if defined(WITH_EMACS_PORT)
EMACS_PORT_NAME=	${WITH_EMACS_PORT}
CONFIGURE_ARGS+=	--with-lispdir=${LOCALBASE}/${EMACS_SITE_LISPDIR}
.else
PLIST_SUB+=		EMACS_SITE_LISPDIR="@comment "
.endif

pre-everything::
	@${ECHO} "============================================================="
	@${ECHO}
	@${ECHO} "You can build ${PKGNAME} with the following options:"
	@${ECHO}
	@${ECHO} "WITH_EMACS_PORT=emacs            with Emacs support"
	@${ECHO}
	@${ECHO} "============================================================="
	@${ECHO}

post-build:
	${SED} -e 's,%%PREFIX%%,${PREFIX},g' ${PKGDIR}/pkg-message >${PKGMESSAGE}

pre-install:
	@${MKDIR} ${PREFIX}/libexec/gnats
	@${SETENV} "PKG_PREFIX=${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@for binary in ${BINARIES}; do \
		${STRIP_CMD} ${PREFIX}/$${binary}; \
	done
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
