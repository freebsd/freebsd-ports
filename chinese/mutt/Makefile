# ex:ts=8
# Ports collection makefile for:  mutt w/pgp hooks
# Date created:			  Thur July 25, 1996
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTREVISION=	2
CATEGORIES=	chinese

MASTERDIR=	${.CURDIR}/../../mail/mutt
REVISEDATE=	20100927
PORTREVISION=	${REVISEDATE}

# XXX: Currently PORTREVISION assignment is not perfect. It needs to
# inherit its master port's PORTREVISION and be appended.

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	The Mongrel of Mail User Agents with Chinese support

CONFLICTS=	ja-mutt-[0-9]* ja-mutt-devel-[0-9]* mutt-[0-9]* mutt-lite-[0-9]*

LIB_DEPENDS+=	hz.0:${PORTSDIR}/chinese/autoconvert

CFLAGS_ADD+=	-D_DONT_USE_CTYPE_INLINE_
LDFLAGS_ADD+=	-lhz

WITH_MUTT_LOCALES_FIX=	yes
WITH_MUTT_NCURSES=	yes
.if !defined(PACKAGE_BUILDING)
WITHOUT_MUTT_SGMLFORMAT=	yes
WITHOUT_MUTT_HTML=		yes
WITHOUT_MUTT_XML=		yes
WITHOUT_MUTT_COMPRESSED_FOLDERS=yes
.endif
MUTT_SLAVE_HTML_PAGES=	1

PKGMESSAGE=	${.CURDIR}/pkg-message

post-patch::
	@${REINPLACE_CMD} -e '/^mutt_SOURCES/s/\\$$/ myiconv.c \\/' ${WRKSRC}/Makefile.am
	@for i in ${.CURDIR}/files/patch-*; do \
		${ECHO_MSG} "===>  Applying extra patch $$i"; \
		${PATCH} ${PATCH_ARGS} < $$i; \
	done

.include "${MASTERDIR}/Makefile"
