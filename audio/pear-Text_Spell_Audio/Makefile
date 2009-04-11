# Ports collection makefile for:  pear-Text_Spell_Audio
# Date created:			  21 Jan 2007
# Whom:				  Ditesh Shashikant Gathani <ditesh@gathani.org>
#
# $FreeBSD$
#

PORTNAME=	Text_Spell_Audio
PORTVERSION=	0.1.0
CATEGORIES=	audio pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Generates a sound clip saying the contents of a string of characters

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

FILES=		Text/Spell/Audio.php en/a.wav en/b.wav en/c.wav en/d.wav \
		en/f.wav en/g.wav en/h.wav en/i.wav en/j.wav en/k.wav en/l.wav \
		en/m.wav en/n.wav en/o.wav en/p.wav en/q.wav en/r.wav en/s.wav \
		en/t.wav en/u.wav en/v.wav en/w.wav en/x.wav en/y.wav en/z.wav \
		en/CAPITAL.wav en/0.wav en/1.wav en/2.wav en/3.wav en/4.wav \
		en/5.wav en/6.wav en/7.wav en/8.wav en/9.wav en/35.wav \
		en/38.wav en/64.wav en/95.wav en/e.wav en/37.wav

EXAMPLES=	example1.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
