# New ports collection makefile for:	ja-gqmpeg
# Date Created:		19 Sep 2001
# Whom:			TATEISHI Katsuyuki <katsu@iec.hiroshima-u.ac.jp>
#
# $FreeBSD$
#

CATEGORIES=	japanese

MAINTAINER=	katsu@iec.hiroshima-u.ac.jp
COMMENT=	Another gtk-based MP3 frontend with Japanese support

.if defined(WITH_SJIS_TAG)
EXTRA_PATCHES=	${.CURDIR}/files/extra-patch-*
.endif

MASTERDIR=	${.CURDIR}/../../audio/gqmpeg
DESCR=		${.CURDIR}/pkg-descr

CONFIGURE_ARGS=	--enable-japanese

NOMAN=		yes

.if !defined(WITH_SJIS_TAG)
pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "If you want to save ID3 tags as SJIS(default: EUC),"
	@${ECHO_MSG} "hit Ctrl-C right now and execute \"make WITH_SJIS_TAG=yes\""
	@${ECHO_MSG}
.endif

pre-install:
	@${REINPLACE_CMD} -Ee 's/(helvetica|lucida)-bold/mincho-medium/g ; \
		s/helvetica|lucida/mincho/g;' ${WRKSRC}/skins/mrclean/skindata*

.include "${MASTERDIR}/Makefile"
