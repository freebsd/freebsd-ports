		Configuration of diclookup-mule FreeBSD port
							    7.Jun.1998
					   MITA Yoshio <mita@jp.FreeBSD.org>
		  Special thanks to MIHIRA Yoshiro <sanpei@yy.cs.keio.ac.jp>

`Diclookup-mule' is a frontend interface for NDTP (Network Dictionary
Transfer Protocol) server on mule.
One of mule (ja-*mule-2.3 or mule-2.3) is necessary for this program.

1. NDTP server installation.

    An NDTP server must therfore be installed.
    Two programs are known as NDTP server: dserver and ndtpd.

    dserver:  Dictionary server.  NDTP has been a protocol for dserver.
	      It supports EB/EBG/EBXA/EPWING CDROM dictionaries.
	      FreeBSD port is ready for installation: ja-dserver-2.2.2
	      Dserver packages includes `dictionary file compression tool'

    ndtpd:    Dserver-compatible Network Dictionary server.  
	      It also supports EB/EBG/EBXA/EPWING CDROM dictionaries.
    Also refer documents to each packages for setup of server.

1. Add startup code to site-start.el
    Typing
	% /usr/local/lib/dserver/setup-diclookup.sh
    displays you `ja-diclookup setup dialog':
     ------------------------ja-diclookup setup --------------------------
     |                                                                   |
     | You have to install appropreate startup code for diclookup-mule.  |
     | This setup script automatically it to:                            |
     | /usr/local/share/mule/19.34/site-lisp/site-start.el.              |
     |                                                                   |
     | Are you sure?                                                     |
     |-------------------------------------------------------------------|
     |                       [ Yes ]         No                          |
     |-------------------------------------------------------------------|
	By answering [ Yes ], startup code is automatically added to
	/usr/local/share/mule/19.34/site-lisp/site-start.el
	(Deinstallation is possible by deinstall-diclookup.sh)

2. Usage.
    Typing `M-x diclookup-mule' launches a new window for dictionary looking up.
	f`word for looking up'[Enter] : Lookup a word
	C`dictionary name'[Enter]     : Change dictionary (TAB complition OK)
	o			      : Switch to other window
	n,p,[ENTER]		      : Move cursor in window.
	Q		              : Quit and delete window.
	q			      : Suspend


                 Dserver FreeBSD portセットアップについて．

                                                             3.Nov.1996
						Revised	    20.Dec.1996
						Revised	    31.Jan.1998
                                         三田吉郎 <mita@jp.FreeBSD.org>


	目次
	0. diclookup-mule 使用の前に.
	I. 起動の準備.
	   I.1. setup.sh の具体的な作業
	II. 削除(uninstall)

diclookup-mule は, mule の上で, 電子辞書を引けるようにするための
プログラムです. これ単体で電子辞書が引けるのではなく, 辞書サーバと
辞書 CDROM (とmule)とを正しくインストールして, はじめて使えるように
なります.  とはいえ, 全く難しくありませんので, 御安心を.

0. diclookup-mule 使用の前に.
    NDTP (Network 辞書転送プロトコル)サーバをインストールして, 動作するように
    しておくことが必須です.
    NDTP サーバとしては, 老舗の dserver や, SRA の笠原さんが開発なさっている 
    ndtpd などが知られています. 
    dserver は, ja-dserver-2.2.2 というパッケージになっています.
    ndtp も近日 FreeBSD ports colleciton に取り込まれることでしょう.
    
    dserver または, ndtp の設定は, それぞれのパッケージに附属の
    文書を参照してください.
    
I. 起動の準備.

    ~/.emacs もしくは ${PREFIX}/share/mule/19.34/site-lisp/site-start.el などの,
    初期設定ファイルに, diclookup-mule 起動のためのエントリを追加します.
    [${PREFIX}/lib/dserver/setup-diclookup.sh] を起動すると, 自動的に
   設定をsite-start.el に追加してくれます．

  ※ ${PREFIX}
     ここで ${PREFIX} とは ports をコンパイル時の環境変数 PREFIX を
     示します. packages では, [/usr/local] となります.  上記の場合,
     [/usr/local/lib/dserver/setup-diclookup.sh] と適時読みかえてください. 

II. site-start.el の再編集.

   setup-diclookup.sh を起動すれば, 自動的に設定を追加してくれるのですが,
   一点だけ修正するところがあります.
   ${PREFIX}/share/mule/19.34/site-lisp/site-start.el の次の行です.

--------
(setq od-dictfile-list '("od-chujiten" "od-kojien" "od-readers" "od-crown")) ; diclookup-mule
--------

   この行では, 使用する辞書 CDROM の中に埋め込まれている外字と, mule で表示
   させるための文字の組み合わせとの対応表 (辞書依存ファイル)を読み込ま
   せています.  上の例では,

    od-chujiten       EBXA 版 研究社新英和・和英中辞典5・3版
    od-kojien         EBXA 版 岩波書店広辞苑
    od-readers        EBXA 版 研究社リーダーズ英和辞典
    od-crown          EBXA 版 三省堂クラウン仏和・独和辞典

   という, 私三田が持っている 8cm CDROM 辞書の辞書依存ファイルを読み込ま
   せています.

   diclookup-mule-2.3.3 には他にも, 次のような辞書依存ファイルが揃って
   いますので, 適宜追加削除します.

    od-chujiten64     EBXA 版 研究社新英和・和英中辞典6・4版
    od-chujiten64-epw EPWING 版 研究社新英和・和英中辞典6・4版
    od-oxford         Oxford コンサイス英英辞典, シソーラス
    od-italian        日外アソシエーツ 現代イタリア語表現辞典

   特に, EPWING 版 研究社新英和・和英中辞典6・4版 は, パシフィック
   ハイテックhttp://www.pht.co.jp/ さんから出ている, 
   FreeBSD Pro 2.2.6J にバンドルされているなど, 
   標準的に売られている辞書なので, この辞書をお持ちの方が増えてくると
   思いますので注意が必要です.
   (蛇足ながら, xanim をインストールして, EPWING 版の新英和中辞典を
    使えば, 音声データを聞くことができます. これで発音もばっちり.)

III. 削除(uninstall)

    削除は，インストールの逆を行えばよいわけですが，自動的に削除を
  行うためのシェルスクリプト，[${PREFIX}/lib/dserver/deinstall.sh] を
  用意しておきました．

    その後で，pkg_deleteを行えばOKのはずです．

質問，不平不満など御座いましたらmita@jp.FreeBSD.orgにどうぞ．
