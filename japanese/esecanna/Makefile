# New ports collection Makefile for: esecanna
# Version required:	0.13.0
# Date created:		24 February 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

DISTNAME=	esecanna_0.13.0
PKGNAME=	ja-esecanna-0.13.0
CATEGORIES=	japanese
MASTER_SITES=	http://www.idaemons.org/ports/distfiles/ \
		http://esecanna.netfort.gr.jp/

MAINTAINER=	knu@idaemons.org

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "elf"
SHLIB_VER=	1
.else
SHLIB_VER=	1.0
.endif

STARTER=	esecanna.sh

MAKE_ENV=	SHLIB_VER="${SHLIB_VER}"

PLIST_SUB=	SHLIB_VER="${SHLIB_VER}" \
		STARTER="${STARTER}"

post-extract:
	@perl -pe " \
		s,!!PREFIX!!,${PREFIX},g; \
		s,!!STARTER!!,${STARTER},g; \
		" \
		${FILESDIR}/esecanna.sh > ${WRKSRC}/${STARTER}

do-configure:
	@cd ${WRKSRC} && perl -i -pe " \
		s,!!PREFIX!!,${PREFIX},g; \
		" \
		README.jp \
		esecannarc

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${STARTER} ${PREFIX}/etc/rc.d/
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/esecanna
	cd ${WRKSRC} && ${INSTALL_DATA} README.First.jp README.jp ${PREFIX}/share/doc/esecanna/
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
