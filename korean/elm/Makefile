# New ports collection makefile for:    elm-2.4h4.1
# Date created:         1 Apr 1997
# Whom:                 Choi Jun Ho <junker@jazz.snu.ac.kr>
#
# $FreeBSD$
#

PORTNAME=	elm
PORTVERSION=	2.4h4.1
CATEGORIES=	korean mail
MASTER_SITES=	ftp://ftp.kaist.ac.kr/pub/hangul/mail/old/Others/ \
		ftp://ftp.kreonet.re.kr/pub/hangul/cair-archive/mail/old/Others/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	cjh@FreeBSD.org
COMMENT=	ELM Mail User Agent, patched for Korean E-Mail

MAN1=		answer.1 checkalias.1 elm.1 elmalias.1 fastmail.1 filter.1\
		frm.1 listalias.1 messages.1 newalias.1 printmail.1 readmsg.1\
		newmail.1

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT= elm-config
CONFIGURE_ENV+= PREFIX="${PREFIX}"

post-install:
	${LN} -fs ${PREFIX}/man/man1/newmail.1.gz ${PREFIX}/man/man1/wnewmail.1.gz
	${LN} -fs ${PREFIX}/man/man1/frm.1.gz ${PREFIX}/man/man1/nfrm.1.gz

.include <bsd.port.mk>
