


xcalendar(1)                                         xcalendar(1)


名称
       xcalendar - X11 用のカレンダーとメモ

書式
       xcalendar [month [year]]


解説
       xcalendar はメモ機能を持ったシンプルな対話型カレンダープロ
       グラムです。このプログラムは X Toolkit と Athena  ま た は
       Motif ウィジェット (コンパイル時のオプションで指定) で作ら
       れています。

       コマンドラインで month と year が指定されなかった場合に は
       現在の年と月が仮定されます。


操作
       日付の上でマウスの左ボタンをクリックするとテキストエディタ
       が起動し、テキストの編集や保存ができます。このテキストはそ
       の日付に関連づけられ、後からエディタで開いて読み書きできま
       す。テキストは calendarDir リソースで指定されたディレク ト
       リ  (デフォルトでは ~/Calendar) に保存されます。エディタか
       らは個々の日付に関連づけられた内容を消去することもで き ま
       す。またエディタ上で日付ラベルの左右にある矢印をクリックす
       れば日の移動ができます。既に開いている日に移動した場合は、
       メッセージが表示され、エディタは表示しかできないモードにな
       ります。

       同様にメインウィンドウにおいて今日の日付ラベルの左右にある
       矢印をクリックすることにより、月を移動することもできます。

       ShowEntries 関数を実行すると、その月にある全ての予定をハイ
       ライト表示できます。デフォルトではこの関数は (年や月が表示
       されている) タイトルウィンドウの中でマウスの左ボタンを押す
       ことにより実行されます。もう一度押すと全ての予定のハイライ
       ト表示を止めます。

       「祝日」は日エディタの下の方にあるテキストウィジェットに表
       示 さ れます。祝日は祝日ファイル (下記の holidayfile 参照)
       から読み取られます。ファイルの形式は mm/dd/yyyy 祝日 内 容
       で、日付と内容の間はタブで区切られます。現在のところワイル
       ドカードは使えません。

欠けている機能
       いろいろ便利な機能が考えられるでしょう。たとえば今日の予定
       を自動的に解釈して約束を検索し、適切な時間にアラーム (リマ
       インダ) を鳴らすという機能が考えられます。実際、このような
       機 能 を実現する xcalendar+ という perl スクリプトがありま
       す。おそらくある日には xcalendar はこの機能を内蔵 す る で
       しょう。

リソース
       リソースデータベースはプログラムの見栄えを変更します。フォ
       ントや縁幅、ラベル、その他のウィジェットで試用されているリ
       ソースが変更可能です。この機能の使い途の一つは曜日や月名の
       変更です。

       変更可能な様々のリソースのウィジェット名には以下のようなも
       のがあります。


            XCalendar    - アプリケーションクラス
            xcalendar    - トップレベルペイン
            controls     - コントロールパネル
            quitButton   - 終了ボタン
            helpButton   - ヘルプボタン
            date         - 日付ラベル
            calendar     - カレンダーぺイン
            daynumbers   - 日付フレーム
            1-49         - 日付ボタン
            daynames     - 曜日フレーム
            MON,TUE,WED,THU,FRI,SAT,SUN - 曜日ボタン
            helpWindow   - ヘルプウィンドウ
            bcontrols    - 月ボタンフレーム
            prev         - 先月ボタン
            succ         - 来月ボタン
            cdate        - 今日の日付ウィジェット
            dayEditor    - エディタポップアップ
            editorFrame  - エディタフレーム
            editorTitle  - エディタタイトル
            editor       - エディタ
            holiday      - 祝日テキスト
            daybuttons   - 日付ボタンフレーム
            prevday      - 前日ボタン
            succday      - 明日ボタン
            editorControls - コントロールパネル
            doneButton   - 終了ボタン
            saveButton   - 保存ボタン
            clearEntry   - 消去ボタン


       アプリケーション特有リソース:


            reverseVideoMark  - True の場合は予定を反転した強調表示にします。
                                デフォルトでは白黒ディスプレイでは True で、
                                カラーディスプレイでは Falase です。

            setMarkBackground - True かつ reverseVideoMark が False の場合、
                                予定の強調表示は背景色が markBackground に
                                なります。

            markBackground    - 予定を強調表示する際に使われる背景色。

            setMarkForeground - setMarkBackground と同様です。

            markForeground    - 予定を強調表示する際に使われる前景色。

            setMarkBackground と setMarkForeground の組合わせは
            どのような値でも構いません。


            january,february,..,december - これらのリソースで月ラベルの月名や
                                oldStyle (下記参照) 時のファイル名決定方法を
                                変更できます。

            firstDay          - 1-7 の整数で週をどの曜日から始めるか指定します。
                                デフォルトは 7 (日曜) です。

            markOnStartup     - True の場合起動時から予定をマークします。
                                デフォルト: True。

            helpFile          - xcalendar.hlp ファイルのフルパス名。
                                デフォルト: %%XCALENDAR_LIBDIR%%/xcalendar.hlp

            textBufferSize    - 日付エディタのテキストバッファの最大サイズ。
                                デフォルト: 2048。

            calendarDir       - $HOME/Calendar 以外のディレクトリにカレンダー
                                ファイルを保存する場合のパス名

            holidayFile       - 祝日を決めるのに用いるファイルのパス名。
                                デフォルト: %%XCALENDAR_LIBDIR%%/xcalendar.hol

            oldStyle          - ファイルの命名規則として新しいスタイル
                                (xcyyyymmdd) ではなく version 3.0 およびそれ
                                以前のファイル命名規則 (xcDAYmonYEAR) を使用
                                します。ここで DAY と YEAR は数字で mon は月
                                の最初の3文字です。
                                デフォルト: True

            markCurrent       - True の場合、今日の日付をマークします (見ら
                                れる場合。カラーディスプレイでのみ便利です)。
                                デフォルト: False

            updateCurrent     - 今日の日付のマーキングを更新する間隔の秒数。
                                デフォルト: 60

            currentForeground - 今日の日付を強調表示する際の前景色。

            markHoliday       - True の場合、祝日をマークします (見られる場合、
                                カラーディスプレイでのみ便利です)。
                                デフォルト: False

            holidayForeground - 祝日を強調表示する際の前景色

            monthnames        - cdate において日付をフォーマットする際に用いる
                                月名を '/' で区切った文字列

            monthnms          - cdate において日付をフォーマットする際に用いる
                                月名の略称を '/' で区切った文字列

            daynames          - cdate において日付をフォーマットする際に用いる
                                曜日名を '/' で区切った文字列

            daynms            - cdate において日付をフォーマットする際に用いる
                                曜日名の略称を '/' で区切った文字列

            date              - cdate において日付をフォーマットする文字列。
                                解釈されるフォーマット文字は次のとおり:

                     %W      曜日の完全な名称
                     %w      曜日の略称
                     %M      月名の完全な名称
                     %m      月名の略称
                     %d      日 (数字)
                     %Y      完全な年数 (4 桁)
                     %y      2 桁の年数

                                デフォルト: "%W, %M %d";


デフォルトのリソースデータベース
            *international: TRUE
            !
            *showGrip:          False
            *calendar*internalBorderWidth: 0
            *input:        True
            *controls*resize: False
            *bcontrols*resize: False
            *daybuttons*resize: False
            *resizable: True
            *title: XCalendar v.4.0
            *dayEditor.title: Day Editor
            *helpWindow.title: XCalendar Help
            *Font: 8x13
            *FontList: 8x13

            *helpFile:     %%XCALENDAR_LIBDIR%%/xcalendar.hlp
            *holidayFile:   %%XCALENDAR_LIBDIR%%/xcalendar.hol

            *firstDay:          7

            *labelType: XmSTRING
            *prev*Label: 先月
            *succ*Label: 来月
            *prevday*Label: 昨日
            *succday*Label: 明日
            *helpButton*Label: 助け
            *quitButton*Label: 終り

            *daynames.SUN.label: \ 日
            *daynames.MON.label: \ 月
            *daynames.TUE.label: \ 火
            *daynames.WED.label: \ 水
            *daynames.THU.label: \ 木
            *daynames.FRI.label: \ 金
            *daynames.SAT.label: \ 土

            *monthnames:   1/2/3/4/5/6/7/8/9/10/11/12
            *monthnms:     1/2/3/4/5/6/7/8/9/10/11/12
            *daynames:     日曜日/月曜日/火曜日/水曜日/木曜日/金曜日/土曜日
            *daynms:  日/月/火/水/木/金/土
            *date:         %M月%d日(%W)


            #ifdef COLOR
            ! colors
            *Background: lightgray
            *markBackground: Steel Blue
            *daynames*Background: lightgray
            *daynames.SUN*Foreground: Red
            *daynames.SAT*Foreground: Black
            *daynumbers*Foreground:   Black
            *daynumbers.1*Foreground: Red
            *daynumbers.8*Foreground: Red
            *daynumbers.15*Foreground: Red
            *daynumbers.22*Foreground: Red
            *daynumbers.29*Foreground: Red
            *daynumbers.36*Foreground: Red
            *helpButton*Background: slategray
            *helpButton*Foreground: White
            *quitButton*Background: slategray
            *quitButton*Foreground: White
            *editorTitle*Background: lightgray
            *editorTitle*Foreground: Black
            *editorControls*Background: lightgray
            *editorControls*Command.Background: slategray
            *editorControls*Command.Foreground: White
            *editorControls*XmPushButton.Background: slategray
            *editorControls*XmPushButton.Foreground: White
            #endif

            *setMarkBackground: True
            *markOnStartup: True
            *markCurrent: True
            *currentForeground: Blue
            *markHoliday: True
            *holidayForeground: Red

            *BorderWidth:       2
            *calendar.borderWidth:   1
            *borderWidth: 0
            *date*borderWidth: 0
            *date*vertDistance: 1
            *prev*vertDistance: 0
            *succ*vertDistance: 0
            *controls*date*fontSet:       8x13bold, -*--14-*
            *daynames*fontSet:            -*--14-*
            *dayEditor*editorTitle*fontSet:    8x13bold, -*--14-*
            *helpWindow*editorTitle*fontSet:   8x13bold, -*--14-*

            *helpButton*vertDistance: 5
            *quitButton*vertDistance: 5
            *editorTitle*vertDistance: 5
            *cdate*vertDistance: 5

            *editorControls*doneButton*label: 終り
            *editorControls*saveButton*label: 保存
            *editorControls*clearEntry*label: 消えてなくなれ
            *doneButton*labelString: 終り
            *saveButton*labelString: 保存
            *clearEntry*labelString: 消えてなくなれ

            *dayEditor*geometry: 300x150
            *helpWindow*geometry: 600x350

            *dayEditor*fontSet:           -*--14-*
            *controls*fontSet:            -*--14-*
            *bcontrols*fontSet:           -*--14-*
            *editorControls*fontSet:      -*--14-*
            *fontSet:                     -*--14-*

            !*preeditType: Root
            !*preeditType: OffTheSpot
            *preeditType: OverTheSpot

            *helpWindow*editorTitle*label: ヘルプ
            *helpWindow*editorTitle*labelString: ヘルプ
            *helpWindow*rows: 15
            *helpWindow*columns: 80
            *rows:7
            *columns: 30

            *dayEditor*Paned*editor.width: 300
            *dayEditor*Paned*editor.height: 150
            *helpWindow*Paned*editor.width: 600
            *helpWindow*Paned*editor.height: 350

            *bcontrols*borderWidth: 0
            *prev*highlightThickness: 0
            *succ*highlightThickness: 0

            *prevday*highlightThickness: 0
            *succday*highlightThickness: 0
            *daybuttons*borderWidth: 0

            *Scrollbar.borderWidth: 1
            *Text*scrollVertical: whenNeeded
            *scrollHorizontal: Never
            *helpWindow*scrollHorizontal: Always
            *holiday*cursorPositionVisible: False
            *holiday*displayCaret: False
            *helpWindow*cursorPositionVisible: False
            *helpWindow*displayCaret: False

            ! Keyboard accelerators
            *editorControls*doneButton*accelerators: #override \n\
                 Meta<Key>q: set() notify() reset() \n
            *editorControls*saveButton*accelerators: #override \n\
                 Meta<Key>s: set() notify() reset() \n
            *editorControls*clearEntry*accelerators: #override \n\
                 Meta<Key>c: set() notify() reset() \n

            *daybuttons*prevday*accelerators: #override \n\
                 Meta<Key>p: set() notify() reset() \n
            *daybuttons*succday*accelerators: #override \n\
                 Meta<Key>n: set() notify() reset() \n

            *prev*accelerators: #override \n\
                 <Key>p: set() notify() reset() \n
            *succ*accelerators: #override \n\
                 <Key>n: set() notify() reset() \n
            *quitButton*accelerators: #override \n\
                 <Key>q: set() notify() \n

            *XmText.translations: #override\n\
                     Ctrl <Key>b:            backward-character()\n\
                     Alt <Key>b:             backward-word()\n\
                     Meta <Key>b:            backward-word()\n\
                     Shift Alt <Key>b:       backward-word(extend)\n\
                     Shift Meta <Key>b:      backward-word(extend)\n\
                     Alt <Key>[:             backward-paragraph()\n\
                     Meta <Key>[:            backward-paragraph()\n\
                     Shift Alt <Key>[:       backward-paragraph(extend)\n\
                     Shift Meta <Key>[:      backward-paragraph(extend)\n\
                     Alt <Key><:             beginning-of-file()\n\
                     Meta <Key><:            beginning-of-file()\n\
                     Ctrl <Key>a:            beginning-of-line()\n\
                     Shift Ctrl <Key>a:      beginning-of-line(extend)\n\
                     Ctrl <Key>osfInsert:    copy-clipboard()\n\
                     Shift <Key>osfDelete:   cut-clipboard()\n\
                     Shift <Key>osfInsert:   paste-clipboard()\n\
                     Alt <Key>>:             end-of-file()\n\
                     Meta <Key>>:            end-of-file()\n\
                     Ctrl <Key>e:            end-of-line()\n\

                     Shift Ctrl <Key>e:      end-of-line(extend)\n\
                     Ctrl <Key>f:            forward-character()\n\
                     Alt <Key>]:             forward-paragraph()\n\
                     Meta <Key>]:            forward-paragraph()\n\
                     Shift Alt <Key>]:       forward-paragraph(extend)\n\
                     Shift Meta <Key>]:      forward-paragraph(extend)\n\
                     Ctrl Alt <Key>f:        forward-word()\n\
                     Ctrl Meta <Key>f:       forward-word()\n\
                     Ctrl <Key>d:            kill-next-character()\n\
                     Ctrl <Key>h:            kill-previous-character()\n\
                     Alt <Key>BackSpace:     kill-previous-word()\n\
                     Meta <Key>BackSpace:    kill-previous-word()\n\
                     Ctrl <Key>w:            key-select() kill-selection()\n\
                     Ctrl <Key>y:            unkill()\n\
                     Ctrl <Key>k:            kill-to-end-of-line()\n\
                     Alt <Key>Delete:        kill-to-start-of-line()\n\
                     Meta <Key>Delete:       kill-to-start-of-line()\n\
                     Ctrl <Key>o:            newline-and-backup()\n\
                     Ctrl <Key>j:            newline-and-indent()\n\
                     Ctrl <Key>n:            next-line()\n\
                     Ctrl <Key>osfLeft:      page-left()\n\
                     Ctrl <Key>osfRight:     page-right()\n\
                     Ctrl <Key>p:            previous-line()\n\
                     Ctrl <Key>g:            process-cancel()\n\
                     Ctrl <Key>l:            redraw-display()\n\
                     Ctrl <Key>v:            next-page()\n\
                     Meta <Key>v:            previous-page()\n\
                     Ctrl <Key>osfDown:      next-page()\n\
                     Ctrl <Key>osfUp:        previous-page()\n\
                     Ctrl <Key>space:        set-anchor()\n


関連ファイル
       $HOME/Calendar/*,      %%XCALENDAR_LIBDIR%%/xcalendar.hlp,
       %%XCALENDAR_LIBDIR%%/xcalendar.hol


関連項目
       xrdb(1), xcalendar+(1)


バグ
       いくつかあると思います。もし見つけたら 私  (bingle@cs.pur-
       due.edu) に教えてください。


作者
       Copyright 1988 by Massachusetts Institute of Technology
       Roman J. Budzianowski, MIT Project Athena

       Copyright 1990-1994 by Purdue University
       Richard Bingle, Department of Computer Sciences

       拡張 / 提案:
       Beth Chaney
       Purdue University, Department of Computer Sciences

       Mike Urban
       Jet Propulsion Labs, NASA

       Joel Neisen
       Minnesota Supercomputer Center

       Hiroshi Kuribayashi
       Omron Corp.























































X Version 11               6 June 1994                          1


